echo "Commands:"
echo "========="
echo ""
#Compilation commands
echo "Compilation of app.c, uart.c, and startup.s ..."

arm-none-eabi-gcc.exe -c -I . -mcpu=arm926ej-s app.c -o app.o
arm-none-eabi-gcc.exe -c -I . -mcpu=arm926ej-s uart.c -o uart.o
arm-none-eabi-as.exe  -mcpu=arm926ej-s -g startup.s -o startup.o

echo "make object dump for all object files "
echo "--------------------------------------"
arm-none-eabi-objdump.exe -h app.o
arm-none-eabi-objdump.exe -h uart.o
arm-none-eabi-objdump.exe -h startup.o

echo "show symbol table for all object files "
echo "--------------------------------------"
echo "app.o:"
arm-none-eabi-nm.exe app.o
echo "uart.o:"
arm-none-eabi-nm.exe uart.o
echo "startup.o:"
arm-none-eabi-nm.exe startup.o

echo "Linking linker_script.ld with object files and generate learn-in-depth.elf ..."
arm-none-eabi-ld.exe -T linker_script.ld startup.o app.o uart.o -o learn-in-depth.elf -Map=Map_file.map

echo "object dump of learn-in-depth.elf:"
arm-none-eabi-objdump.exe -h learn-in-depth.elf
echo ""
echo "analyze the executable file:"
arm-none-eabi-nm learn-in-depth.elf

echo "generate binary file ..."
arm-none-eabi-objcopy -O binary learn-in-depth.elf learn-in-depth.bin
echo "============================================================"
echo "simulation on gemu"
echo "============================================================"
qemu-system-arm -M versatilepb -m 128M -nographic -kernel learn-in-depth.bin