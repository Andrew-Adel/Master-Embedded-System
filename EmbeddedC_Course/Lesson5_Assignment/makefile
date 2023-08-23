#@copyright : Andrew Adel
#toolchain
CC=arm-none-eabi-
#repeated options
CFLAGS =-mcpu=cortex-m3 -mthumb
INCS =-I .
LIBS =

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)

Project_Name=unit3_lesson5_lab5

all: $(Project_Name).bin
	@echo "================Build is Done================"

startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(Project_Name).elf: $(SRC) $(As)
# 	$(CC)ld.exe -T linker_script.ld -L<>arm-none-eabi.stdlib.o $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	$(CC)gcc $(CFLAGS) -nostartfiles -T linker_script.ld $(SRC) $(As) -o $@
	$(CC)gcc -E main.c -o main.i
	
$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy -O binary $< $@
	$(CC)objdump -D $< > $(Project_Name).txt

clean_all:
	rm *.o *.elf *.bin *.i *.map *.txt

clean:
	rm *.elf *.bin