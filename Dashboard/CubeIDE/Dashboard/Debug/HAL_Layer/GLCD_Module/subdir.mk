################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL_Layer/GLCD_Module/LCD_program.c 

OBJS += \
./HAL_Layer/GLCD_Module/LCD_program.o 

C_DEPS += \
./HAL_Layer/GLCD_Module/LCD_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL_Layer/GLCD_Module/%.o HAL_Layer/GLCD_Module/%.su HAL_Layer/GLCD_Module/%.cyclo: ../HAL_Layer/GLCD_Module/%.c HAL_Layer/GLCD_Module/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/Dashboard/CubeIDE/Dashboard/APPLICATION_Layer/DISPLAY_Module" -I"/home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/Dashboard/CubeIDE/Dashboard/APPLICATION_Layer/GET_Module" -I"/home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/Dashboard/CubeIDE/Dashboard/APPLICATION_Layer/RTC_Module" -I"/home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/Dashboard/CubeIDE/Dashboard/APPLICATION_Layer/OBSERVER_Module" -I"/home/ahmed-ferganey/Desktop/MyGitHub/GraduationProject/Dashboard/CubeIDE/Dashboard/COMMON_Layer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL_Layer-2f-GLCD_Module

clean-HAL_Layer-2f-GLCD_Module:
	-$(RM) ./HAL_Layer/GLCD_Module/LCD_program.cyclo ./HAL_Layer/GLCD_Module/LCD_program.d ./HAL_Layer/GLCD_Module/LCD_program.o ./HAL_Layer/GLCD_Module/LCD_program.su

.PHONY: clean-HAL_Layer-2f-GLCD_Module

