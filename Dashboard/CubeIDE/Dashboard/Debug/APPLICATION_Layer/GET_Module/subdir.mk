################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APPLICATION_Layer/GET_Module/GET_program.c 

OBJS += \
./APPLICATION_Layer/GET_Module/GET_program.o 

C_DEPS += \
./APPLICATION_Layer/GET_Module/GET_program.d 


# Each subdirectory must supply rules for building sources it contributes
APPLICATION_Layer/GET_Module/%.o APPLICATION_Layer/GET_Module/%.su APPLICATION_Layer/GET_Module/%.cyclo: ../APPLICATION_Layer/GET_Module/%.c APPLICATION_Layer/GET_Module/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/Dashboard/CubeIDE/Dashboard/APPLICATION_Layer/DISPLAY_Module" -I"/home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/Dashboard/CubeIDE/Dashboard/APPLICATION_Layer/GET_Module" -I"/home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/Dashboard/CubeIDE/Dashboard/APPLICATION_Layer/RTC_Module" -I"/home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/Dashboard/CubeIDE/Dashboard/APPLICATION_Layer/OBSERVER_Module" -I"/home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/Dashboard/CubeIDE/Dashboard/COMMON_Layer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-APPLICATION_Layer-2f-GET_Module

clean-APPLICATION_Layer-2f-GET_Module:
	-$(RM) ./APPLICATION_Layer/GET_Module/GET_program.cyclo ./APPLICATION_Layer/GET_Module/GET_program.d ./APPLICATION_Layer/GET_Module/GET_program.o ./APPLICATION_Layer/GET_Module/GET_program.su

.PHONY: clean-APPLICATION_Layer-2f-GET_Module

