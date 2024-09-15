CPPFILES = $(wildcard *.cpp io/*.cpp)
OBJS = $(CPPFILES:.cpp=.o)
GPPFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles
GCCPATH = /usr/bin

all: clean kernel8.img

boot.o: boot.S
	$(GCCPATH)/aarch64-none-elf-gcc $(GCCFLAGS) -c boot.S -o boot.o

%.o: %.cpp
	$(GCCPATH)/aarch64-none-elf-g++ $(GCCFLAGS) -c $< -o $@

kernel8.img: boot.o $(OBJS)
	$(GCCPATH)/aarch64-none-elf-g++  -nostdlib boot.o $(OBJS) -T link.ld -o kernel8.elf
	$(GCCPATH)/aarch64-none-elf-objcopy -O binary kernel8.elf kernel8.img

clean:
	/bin/rm kernel8.elf *.o *.img > /dev/null 2> /dev/null || true
