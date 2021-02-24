################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Eeprom_prg.c \
../I2C_prg.c \
../Pass_Updater_Prog.c \
../UART_PROG.c \
../main.c 

OBJS += \
./Eeprom_prg.o \
./I2C_prg.o \
./Pass_Updater_Prog.o \
./UART_PROG.o \
./main.o 

C_DEPS += \
./Eeprom_prg.d \
./I2C_prg.d \
./Pass_Updater_Prog.d \
./UART_PROG.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


