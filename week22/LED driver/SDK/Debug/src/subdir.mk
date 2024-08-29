################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DIO_prog.c \
../src/LED_config.c \
../src/LED_prog.c \
../src/SW_config.c \
../src/SW_prog.c \
../src/main.c 

OBJS += \
./src/DIO_prog.o \
./src/LED_config.o \
./src/LED_prog.o \
./src/SW_config.o \
./src/SW_prog.o \
./src/main.o 

C_DEPS += \
./src/DIO_prog.d \
./src/LED_config.d \
./src/LED_prog.d \
./src/SW_config.d \
./src/SW_prog.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


