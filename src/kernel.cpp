#include "Constants.h"
#include "io/io.h"

int main() {
  const char *helloMessage = "Hello, World!\n";
  uart_init();
  uart_writeText(helloMessage);
  uart_writeText("This is a test message.\n");

  while (1) {
    ;
  }

  return 0;
}
