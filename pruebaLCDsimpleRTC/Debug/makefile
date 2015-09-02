################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/FW_Inicializaciones/subdir.mk
-include src/FW_Drivers/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: pruebaLCDsimpleRTC.axf

# Tool invocations
pruebaLCDsimpleRTC.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="pruebaLCDsimpleRTC.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "pruebaLCDsimpleRTC_Debug.ld" -o "pruebaLCDsimpleRTC.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) pruebaLCDsimpleRTC.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "pruebaLCDsimpleRTC.axf"; # arm-none-eabi-objcopy -v -O binary "pruebaLCDsimpleRTC.axf" "pruebaLCDsimpleRTC.bin" ; # checksum -p LPC1769 -d "pruebaLCDsimpleRTC.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
