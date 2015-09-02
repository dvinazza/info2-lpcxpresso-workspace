################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../TPL2-B-Drivers/FW_Expansion_2.c \
../TPL2-B-Drivers/Oscilador.c \
../TPL2-B-Drivers/TPL2-B-FW-CONFIG.c \
../TPL2-B-Drivers/TPL2-B-FW-GPIO.c \
../TPL2-B-Drivers/TPL2-B-FW-INIC.c \
../TPL2-B-Drivers/cr_startup_lpc176x.c \
../TPL2-B-Drivers/crp.c 

OBJS += \
./TPL2-B-Drivers/FW_Expansion_2.o \
./TPL2-B-Drivers/Oscilador.o \
./TPL2-B-Drivers/TPL2-B-FW-CONFIG.o \
./TPL2-B-Drivers/TPL2-B-FW-GPIO.o \
./TPL2-B-Drivers/TPL2-B-FW-INIC.o \
./TPL2-B-Drivers/cr_startup_lpc176x.o \
./TPL2-B-Drivers/crp.o 

C_DEPS += \
./TPL2-B-Drivers/FW_Expansion_2.d \
./TPL2-B-Drivers/Oscilador.d \
./TPL2-B-Drivers/TPL2-B-FW-CONFIG.d \
./TPL2-B-Drivers/TPL2-B-FW-GPIO.d \
./TPL2-B-Drivers/TPL2-B-FW-INIC.d \
./TPL2-B-Drivers/cr_startup_lpc176x.d \
./TPL2-B-Drivers/crp.d 


# Each subdirectory must supply rules for building sources it contributes
TPL2-B-Drivers/%.o: ../TPL2-B-Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"D:\InfoII_2014\Clase x Clase_2014\Clase 8-Display 7seg\workspace_Display_2014\TPL2-B\Primitivas" -I"D:\InfoII_2014\Clase x Clase_2014\Clase 8-Display 7seg\workspace_Display_2014\TPL2-B\TPL2-B-Aplicacion" -I"D:\InfoII_2014\Clase x Clase_2014\Clase 8-Display 7seg\workspace_Display_2014\TPL2-B\TPL2-B-Drivers" -I"D:\InfoII_2014\Clase x Clase_2014\Clase 8-Display 7seg\workspace_Display_2014\TPL2-B\TPL2-B-Headers" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


