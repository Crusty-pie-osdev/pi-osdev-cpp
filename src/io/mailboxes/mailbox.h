#include "constants.h"
#include "io.h"
class enum MailBox {
    public: unsigned int read(unsigned char ch);
    private: volatile unsigned int __attribute__((aligned(16))) buffer[36];
}
