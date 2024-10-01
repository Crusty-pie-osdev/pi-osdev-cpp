#include "Constants.h"
#include "io/io.h"

int main() {
  const char *helloMessage = "Hello, World!\n";
  uart_init();
  uart_writeText(helloMessage);

  while (1) {
    ;
  }

  return 0;
}
