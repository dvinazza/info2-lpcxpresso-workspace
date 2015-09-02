################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Oscilador.c \
../Drivers/TPL3-FW-CONFIG.c \
../Drivers/TPL3-FW-Expansion_2.c \
../Drivers/TPL3-FW-GPIO.c \
../Drivers/TPL3-FW-INIC.c \
../Drivers/cr_startup_lpc176x.c \
../Drivers/crp.c \
../Drivers/driver_teclado.c 

OBJS += \
./Drivers/Oscilador.o \
./Drivers/TPL3-FW-CONFIG.o \
./Drivers/TPL3-FW-Expansion_2.o \
./Drivers/TPL3-FW-GPIO.o \
./Drivers/TPL3-FW-INIC.o \
./Drivers/cr_startup_lpc176x.o \
./Drivers/crp.o \
./Drivers/driver_teclado.o 

C_DEPS += \
./Drivers/Oscilador.d \
./Drivers/TPL3-FW-CONFIG.d \
./Drivers/TPL3-FW-Expansion_2.d \
./Drivers/TPL3-FW-GPIO.d \
./Drivers/TPL3-FW-INIC.d \
./Drivers/cr_startup_lpc176x.d \
./Drivers/crp.d \
./Drivers/driver_teclado.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/%.o: ../Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"/home/dvinazza/git/utn/info2/info2-lpcxpresso-workspace/TPL3/Headers" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


