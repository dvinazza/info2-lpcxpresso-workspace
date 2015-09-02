################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../TPL2-B-Aplicacion/TPL2-B-Aplicacion.c 

OBJS += \
./TPL2-B-Aplicacion/TPL2-B-Aplicacion.o 

C_DEPS += \
./TPL2-B-Aplicacion/TPL2-B-Aplicacion.d 


# Each subdirectory must supply rules for building sources it contributes
TPL2-B-Aplicacion/%.o: ../TPL2-B-Aplicacion/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"D:\InfoII_2014\Clase x Clase_2014\Clase 8-Display 7seg\workspace_Display_2014\TPL2-B\Primitivas" -I"D:\InfoII_2014\Clase x Clase_2014\Clase 8-Display 7seg\workspace_Display_2014\TPL2-B\TPL2-B-Aplicacion" -I"D:\InfoII_2014\Clase x Clase_2014\Clase 8-Display 7seg\workspace_Display_2014\TPL2-B\TPL2-B-Drivers" -I"D:\InfoII_2014\Clase x Clase_2014\Clase 8-Display 7seg\workspace_Display_2014\TPL2-B\TPL2-B-Headers" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


