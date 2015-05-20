################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TecladoHW.c \
../src/cr_startup_lpc175x_6x.c \
../src/cr_startup_lpc176x.c \
../src/crp.c \
../src/gpio.c 

OBJS += \
./src/TecladoHW.o \
./src/cr_startup_lpc175x_6x.o \
./src/cr_startup_lpc176x.o \
./src/crp.o \
./src/gpio.o 

C_DEPS += \
./src/TecladoHW.d \
./src/cr_startup_lpc175x_6x.d \
./src/cr_startup_lpc176x.d \
./src/crp.d \
./src/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


