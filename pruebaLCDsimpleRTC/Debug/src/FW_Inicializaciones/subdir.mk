################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FW_Inicializaciones/FW_InitBaseBoard.c \
../src/FW_Inicializaciones/FW_InitKit_principal.c \
../src/FW_Inicializaciones/FW_InitOscilador.c \
../src/FW_Inicializaciones/cr_startup_lpc176x.c 

OBJS += \
./src/FW_Inicializaciones/FW_InitBaseBoard.o \
./src/FW_Inicializaciones/FW_InitKit_principal.o \
./src/FW_Inicializaciones/FW_InitOscilador.o \
./src/FW_Inicializaciones/cr_startup_lpc176x.o 

C_DEPS += \
./src/FW_Inicializaciones/FW_InitBaseBoard.d \
./src/FW_Inicializaciones/FW_InitKit_principal.d \
./src/FW_Inicializaciones/FW_InitOscilador.d \
./src/FW_Inicializaciones/cr_startup_lpc176x.d 


# Each subdirectory must supply rules for building sources it contributes
src/FW_Inicializaciones/%.o: ../src/FW_Inicializaciones/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -I"/home/dvinazza/git/utn/info2/info2-lpcxpresso-workspace/pruebaLCDsimpleRTC/src/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


