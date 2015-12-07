################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FW_drivers/FW_GPIO.c \
../src/FW_drivers/FW_SYSTICK.c \
../src/FW_drivers/FW_Serie.c \
../src/FW_drivers/FW_TECLADO.c \
../src/FW_drivers/FW_UART0.c 

OBJS += \
./src/FW_drivers/FW_GPIO.o \
./src/FW_drivers/FW_SYSTICK.o \
./src/FW_drivers/FW_Serie.o \
./src/FW_drivers/FW_TECLADO.o \
./src/FW_drivers/FW_UART0.o 

C_DEPS += \
./src/FW_drivers/FW_GPIO.d \
./src/FW_drivers/FW_SYSTICK.d \
./src/FW_drivers/FW_Serie.d \
./src/FW_drivers/FW_TECLADO.d \
./src/FW_drivers/FW_UART0.d 


# Each subdirectory must supply rules for building sources it contributes
src/FW_drivers/%.o: ../src/FW_drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"/home/dvinazza/git/utn/info2/info2-lpcxpresso-workspace/Serial_prueba/src/FW_drivers" -I"/home/dvinazza/git/utn/info2/info2-lpcxpresso-workspace/Serial_prueba/src/FW_inicializaciones" -I"/home/dvinazza/git/utn/info2/info2-lpcxpresso-workspace/Serial_prueba/src/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


