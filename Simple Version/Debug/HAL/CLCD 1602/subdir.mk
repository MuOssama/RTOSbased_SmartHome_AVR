################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/CLCD\ 1602/CLCD_PROGRAM.c 

OBJS += \
./HAL/CLCD\ 1602/CLCD_PROGRAM.o 

C_DEPS += \
./HAL/CLCD\ 1602/CLCD_PROGRAM.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/CLCD\ 1602/CLCD_PROGRAM.o: ../HAL/CLCD\ 1602/CLCD_PROGRAM.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"HAL/CLCD 1602/CLCD_PROGRAM.d" -MT"HAL/CLCD\ 1602/CLCD_PROGRAM.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


