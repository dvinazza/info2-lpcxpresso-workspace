################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FW_inicializaciones/FW_InitGPIOBaseBoard.c \
../src/FW_inicializaciones/FW_InitKit_principal.c \
../src/FW_inicializaciones/FW_InitOscilador.c \
../src/FW_inicializaciones/FW_initSYSTICK.c \
../src/FW_inicializaciones/FW_initUART0.c \
../src/FW_inicializaciones/cr_startup_lpc176x.c 

OBJS += \
./src/FW_inicializaciones/FW_InitGPIOBaseBoard.o \
./src/FW_inicializaciones/FW_InitKit_principal.o \
./src/FW_inicializaciones/FW_InitOscilador.o \
./src/FW_inicializaciones/FW_initSYSTICK.o \
./src/FW_inicializaciones/FW_initUART0.o \
./src/FW_inicializaciones/cr_startup_lpc176x.o 

C_DEPS += \
./src/FW_inicializaciones/FW_InitGPIOBaseBoard.d \
./src/FW_inicializaciones/FW_InitKit_principal.d \
./src/FW_inicializaciones/FW_InitOscilador.d \
./src/FW_inicializaciones/FW_initSYSTICK.d \
./src/FW_inicializaciones/FW_initUART0.d \
./src/FW_inicializaciones/cr_startup_lpc176x.d 


# Each subdirectory must supply rules for building sources it contributes
src/FW_inicializaciones/%.o: ../src/FW_inicializaciones/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"/home/dvinazza/git/utn/info2/info2-lpcxpresso-workspace/Serial_prueba/src/FW_drivers" -I"/home/dvinazza/git/utn/info2/info2-lpcxpresso-workspace/Serial_prueba/src/FW_inicializaciones" -I"/home/dvinazza/git/utn/info2/info2-lpcxpresso-workspace/Serial_prueba/src/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


