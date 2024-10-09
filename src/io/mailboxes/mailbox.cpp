#include "mailbox.h"

unsigned int MailBox::read(unsigned char ch) {
    // 28-bit address (MSB) and 4-bit value (LSB)
    unsigned int r = ((unsigned int)((long)&mbox) & ~0xF) | (ch & 0xF);

    // Wait until we can write
    while (mmio_read(constants::mailbox::MailboxStatus) & constants::mailbox::MailboxFull) {
    };

    // Write the address of our buffer to the mailbox with the channel appended
    mmio_write(constants::mailbox::MailboxWrite, r);

    while (1) {
        // Is there a reply?
        while (mmio_read(constants::mailbox::MailboxStatus) & constants::mailbox::MailboxEmpty) {
        };

        // Is it a reply to our message?
        if (r == mmio_read(constants::mailbox::MailboxRead))
            return mbox[1] == constants::mailbox::MailboxResponse; // Is it successful?
    }
    return 0;
}
