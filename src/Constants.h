#pragma once

namespace constants {
namespace gpio {

constexpr unsigned long long GpioRegisterBase =
    0xFE200000; // 0xFE000000 was used previously in
constexpr unsigned long long GpfSel0 = GpioRegisterBase + 0x00;
constexpr unsigned long long GpSet0 = GpioRegisterBase + 0x01C;
constexpr unsigned long long GpClr0 = GpioRegisterBase + 0x28;
constexpr unsigned long long GpPupPdn0 = GpioRegisterBase + 0xE4;

constexpr int MaxPin = 53;
constexpr int FunctionAlt5 = 2;

constexpr int PullNone = 0;

} // namespace gpio

namespace uart {
constexpr unsigned long long AuxBase = 0xFe215000;
constexpr unsigned long long AuxEnables = AuxBase + 0x04;
constexpr unsigned long long AuxMuIoReg = AuxBase + 0x40;
constexpr unsigned long long AuxMuIerReg = AuxBase + 0x44;
constexpr unsigned long long AuxMuIirReg = AuxBase + 0x48;
constexpr unsigned long long AuxMuLcrReg = AuxBase + 0x4C;
constexpr unsigned long long AuxMuMcrReg = AuxBase + 0x50;
constexpr unsigned long long AuxMuLsrReg = AuxBase + 0x54;
constexpr unsigned long long AuxMuCntlReg = AuxBase + 0x60;
constexpr unsigned long long AuxMuBaudReg = AuxBase + 0x68;
constexpr unsigned long long AuxUartClock = 500000000;
constexpr unsigned long long UartMaxQueue = 16 * 1024;
} // namespace uart
} // namespace constants
