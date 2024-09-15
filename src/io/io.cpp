#include "io.h"
#include "../Constants.h"
// GPIO
void mmio_write(long reg, unsigned int val) {
  *(volatile unsigned int *)reg = val;
}
unsigned int mmio_read(long reg) { return *(volatile unsigned int *)reg; }

unsigned int gpio_call(unsigned int pin_number, unsigned int value,
                       unsigned int base, unsigned int field_size,
                       unsigned int field_max) {
  unsigned int field_mask = (1 << field_size) - 1;

  if (pin_number > field_max)
    return 0;
  if (value > field_mask)
    return 0;

  unsigned int num_fields = 32 / field_size;
  unsigned int reg = base + ((pin_number / num_fields) * 4);
  unsigned int shift = (pin_number % num_fields) * field_size;

  unsigned int curval = mmio_read(reg);
  curval &= ~(field_mask << shift);
  curval |= value << shift;
  mmio_write(reg, curval);

  return 1;
}

unsigned int gpio_set(unsigned int pin_number, unsigned int value) {
  return gpio_call(pin_number, value, constants::gpio::GpSet0, 1,
                   constants::gpio::MaxPin);
}
unsigned int gpio_clear(unsigned int pin_number, unsigned int value) {
  return gpio_call(pin_number, value, constants::gpio::GpClr0, 1,
                   constants::gpio::MaxPin);
}
unsigned int gpio_pull(unsigned int pin_number, unsigned int value) {
  return gpio_call(pin_number, value, constants::gpio::GpPupPdn0, 2,
                   constants::gpio::MaxPin);
}
unsigned int gpio_function(unsigned int pin_number, unsigned int value) {
  return gpio_call(pin_number, value, constants::gpio::GpfSel0, 3,
                   constants::gpio::MaxPin);
}

void gpio_useAsAlt5(unsigned int pin_number) {
  gpio_pull(pin_number, constants::gpio::PullNone);
  gpio_function(pin_number, constants::gpio::FunctionAlt5);
}

// UART
#define AUX_MU_BAUD(baud) ((constants::uart::AuxUartClock / (baud * 8)) - 1)

void uart_init() {
  mmio_write(constants::uart::AuxEnables, 1); // enable UART1
  mmio_write(constants::uart::AuxMuIerReg, 0);
  mmio_write(constants::uart::AuxMuCntlReg, 0);
  mmio_write(constants::uart::AuxMuLcrReg, 3); // 8 bits
  mmio_write(constants::uart::AuxMuMcrReg, 0);
  mmio_write(constants::uart::AuxMuIerReg, 0);
  mmio_write(constants::uart::AuxMuIirReg, 0xC6); // disable interrupts
  mmio_write(constants::uart::AuxMuBaudReg, AUX_MU_BAUD(115200));
  gpio_useAsAlt5(14);
  gpio_useAsAlt5(15);
  mmio_write(constants::uart::AuxMuCntlReg, 3); // enable RX/TX
}

unsigned int uart_isWriteByteReady() {
  return mmio_read(constants::uart::AuxMuLsrReg) & 0x20;
}

void uart_writeByteBlockingActual(unsigned char ch) {
  while (!uart_isWriteByteReady())
    ;
  mmio_write(constants::uart::AuxMuIoReg, (unsigned int)ch);
}

void uart_writeText(const char *buffer) {
  while (*buffer) {
    if (*buffer == '\n')
      uart_writeByteBlockingActual('\r');
    uart_writeByteBlockingActual(*buffer++);
  }
}

// Framebuffer/message boxes WIP
