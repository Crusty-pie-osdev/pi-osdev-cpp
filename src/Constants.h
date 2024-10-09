#pragma once
namespace constants {

// HIGH PERIPHERAL BASE ADDRESSES
// The low peripheral gpio register base is 0xFE000000,

namespace gpio {
constexpr unsigned long long GpioRegisterBase = 0xFE200000;
constexpr unsigned long long GpfSel0          = GpioRegisterBase + 0x00;
constexpr unsigned long long GpSet0           = GpioRegisterBase + 0x01C;
constexpr unsigned long long GpClr0           = GpioRegisterBase + 0x28;
constexpr unsigned long long GpPupPdn0        = GpioRegisterBase + 0xE4;
constexpr int                MaxPin           = 53;
constexpr int                FunctionAlt5     = 2;
constexpr int                PullNone         = 0;
} // namespace gpio

namespace uart {
constexpr unsigned long long AuxBase      = 0xFe215000;
constexpr unsigned long long AuxEnables   = AuxBase + 0x04;
constexpr unsigned long long AuxMuIoReg   = AuxBase + 0x40;
constexpr unsigned long long AuxMuIerReg  = AuxBase + 0x44;
constexpr unsigned long long AuxMuIirReg  = AuxBase + 0x48;
constexpr unsigned long long AuxMuLcrReg  = AuxBase + 0x4C;
constexpr unsigned long long AuxMuMcrReg  = AuxBase + 0x50;
constexpr unsigned long long AuxMuLsrReg  = AuxBase + 0x54;
constexpr unsigned long long AuxMuCntlReg = AuxBase + 0x60;
constexpr unsigned long long AuxMuBaudReg = AuxBase + 0x68;
constexpr unsigned long long AuxUartClock = 500000000;
constexpr unsigned long long UartMaxQueue = 16 * 1024;
} // namespace uart

namespace mailbox {
constexpr unsigned long long VideoCoreMailboxBase = 0xFE20B880;
constexpr unsigned long long MailboxRead          = VideoCoreMailboxBase + 0x00;
constexpr unsigned long long MailboxPoll          = VideoCoreMailboxBase + 0x10;
constexpr unsigned long long MailboxSend          = VideoCoreMailboxBase + 0x14;
constexpr unsigned long long MailboxStatus        = VideoCoreMailboxBase + 0x18;
constexpr unsigned long long MailboxConfig        = VideoCoreMailboxBase + 0x1C;
constexpr unsigned long long MailboxWrite         = VideoCoreMailboxBase + 0x20;
constexpr unsigned long long MailboxResponse      = 0x80000000;
constexpr unsigned long long MailboxFull          = 0x80000000;
constexpr unsigned long long MailboxEmpty         = 0x40000000;
} // namespace mailbox

} // namespace constants
