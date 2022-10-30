################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SHIFT_REGISTER/SHIFT_REGISTER_PROGRAM.c 

OBJS += \
./HAL/SHIFT_REGISTER/SHIFT_REGISTER_PROGRAM.o 

C_DEPS += \
./HAL/SHIFT_REGISTER/SHIFT_REGISTER_PROGRAM.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/SHIFT_REGISTER/%.o: ../HAL/SHIFT_REGISTER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


