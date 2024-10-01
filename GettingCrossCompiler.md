
Don't run this without modifying for your own needs. This is just a reference that is not meant to be run as is.

```bash
wget https://developer.arm.com/-/media/Files/downloads/gnu/13.3.rel1/binrel/arm-gnu-toolchain-13.3.rel1-x86_64-aarch64-none-elf.tar.xz
tar -xf arm-gnu-toolchain-13.3.rel1-x86_64-aarch64-none-elf.tar.xz
# Add to /usr/bin
sudo ln -s ~/pi-osdev-cpp/cross_compiler/arm-gnu-toolchain-13.3.rel1-x86_64-aarch64-none-elf/bin/aarch64-none-elf-gcc /usr/bin/aarch64-none-elf-gcc
sudo ln -s ~/pi-osdev-cpp/cross_compiler/arm-gnu-toolchain-13.3.rel1-x86_64-aarch64-none-elf/bin/aarch64-none-elf-g++ /usr/bin/aarch64-none-elf-g++
sudo ln -s ~/pi-osdev-cpp/cross_compiler/arm-gnu-toolchain-13.3.rel1-x86_64-aarch64-none-elf/bin/aarch64-none-elf-objcopy /usr/bin/aarch64-none-elf-objcopy
sudo ln -s ~/pi-osdev-cpp/cross_compiler/arm-gnu-toolchain-13.3.rel1-x86_64-aarch64-none-elf/bin/aarch64-none-elf-objdump /usr/bin/aarch64-none-elf-objdump

```
