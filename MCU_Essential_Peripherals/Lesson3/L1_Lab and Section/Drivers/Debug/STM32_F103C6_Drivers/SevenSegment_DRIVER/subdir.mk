################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_F103C6_Drivers/SevenSegment_DRIVER/SevenSegmentComAnode.c 

OBJS += \
./STM32_F103C6_Drivers/SevenSegment_DRIVER/SevenSegmentComAnode.o 

C_DEPS += \
./STM32_F103C6_Drivers/SevenSegment_DRIVER/SevenSegmentComAnode.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_F103C6_Drivers/SevenSegment_DRIVER/SevenSegmentComAnode.o: ../STM32_F103C6_Drivers/SevenSegment_DRIVER/SevenSegmentComAnode.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Courses/Embedded System KS/2) Second Term/Units/Unit 7/Repo/Master-Embedded-System/MCU_Essential_Peripherals/Lesson3/L1_Lab/Drivers/STM32_F103C6_Drivers/SevenSegment_DRIVER" -I"E:/Courses/Embedded System KS/2) Second Term/Units/Unit 7/Repo/Master-Embedded-System/MCU_Essential_Peripherals/Lesson3/L1_Lab/Drivers/STM32_F103C6_Drivers/LCD_DRIVER" -I"E:/Courses/Embedded System KS/2) Second Term/Units/Unit 7/Repo/Master-Embedded-System/MCU_Essential_Peripherals/Lesson3/L1_Lab/Drivers/STM32_F103C6_Drivers/KEYPAD_DRIVER" -I"E:/Courses/Embedded System KS/2) Second Term/Units/Unit 7/Repo/Master-Embedded-System/MCU_Essential_Peripherals/Lesson3/L1_Lab/Drivers/STM32_F103C6_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_Drivers/SevenSegment_DRIVER/SevenSegmentComAnode.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

