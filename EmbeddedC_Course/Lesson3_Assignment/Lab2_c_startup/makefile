#@copyright : Andrew Adel
#toolchain
CC=arm-none-eabi-
#repeated options
CFLAGS =-mcpu=cortex-m3 -mthumb -gdwarf-2
INCS =-I .
LIBS =
#souce files .c
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)	#source files after compilation
#source files .s
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)	#source files after compilation
#project name
Project_Name=learn_in_depth_cortex_M3


# default make
all: $(Project_Name).bin
	@echo "================Build is Done================"

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $< -o $@
#linking all objects files to .elf file and generate map file
$(Project_Name).elf: $(OBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) -o $@ -Map=Map_file.map
#generate binary file which will be executed
$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy -O binary $< $@	 
#remove all .o .elf .bin .map files
clean_all:
	rm *.o *.elf *.bin *.map
#remove only final files
clean:
	rm *.elf *.bin *.map