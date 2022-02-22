################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_PROGRAM.c \
../EEPROM_PROGRAM.c \
../Heater_Program.c \
../main.c 

OBJS += \
./ADC_PROGRAM.o \
./EEPROM_PROGRAM.o \
./Heater_Program.o \
./main.o 

C_DEPS += \
./ADC_PROGRAM.d \
./EEPROM_PROGRAM.d \
./Heater_Program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


