################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/inc/subdir.mk
-include src/PRimitivas/subdir.mk
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
all: Teclado4x1.axf

# Tool invocations
Teclado4x1.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="Teclado4x1.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "Teclado4x1_Debug.ld" -o "Teclado4x1.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) Teclado4x1.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Teclado4x1.axf"; # arm-none-eabi-objcopy -O binary "Teclado4x1.axf" "Teclado4x1.bin" ; checksum -p LPC1769 -d "Teclado4x1.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
