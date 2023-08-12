################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := ARM _Config_CubeMX
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
ARM\ _Config_CubeMX.elf \

MAP_FILES += \
ARM\ _Config_CubeMX.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
ARM\ _Config_CubeMX.list \

OBJCOPY_HEX += \
ARM\ _Config_CubeMX.hex \

OBJCOPY_BIN += \
ARM\ _Config_CubeMX.bin \


# All Target
all: main-build

# Main-build Target
main-build: ARM\ _Config_CubeMX.elf secondary-outputs

# Tool invocations
ARM\ _Config_CubeMX.elf ARM\ _Config_CubeMX.map: $(OBJS) $(USER_OBJS) C:\Users\Ahmed\ Ferganey\Downloads\Puplic-Github\ARM_Grad_Project\ARM\ _Config_CubeMX\STM32F103C4TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "ARM _Config_CubeMX.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\Ahmed Ferganey\Downloads\Puplic-Github\ARM_Grad_Project\ARM _Config_CubeMX\STM32F103C4TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="ARM _Config_CubeMX.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

ARM\ _Config_CubeMX.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ARM _Config_CubeMX.list"
	@echo 'Finished building: $@'
	@echo ' '

ARM\ _Config_CubeMX.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "ARM _Config_CubeMX.hex"
	@echo 'Finished building: $@'
	@echo ' '

ARM\ _Config_CubeMX.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "ARM _Config_CubeMX.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ARM\ _Config_CubeMX.bin ARM\ _Config_CubeMX.elf ARM\ _Config_CubeMX.hex ARM\ _Config_CubeMX.list ARM\ _Config_CubeMX.map ARM\\ _Config_CubeMX.elf default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
