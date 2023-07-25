################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/lauta/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/BSP/STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.c 

OBJS += \
./STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.o 

C_DEPS += \
./STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.o: C:/Users/lauta/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/BSP/STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.c STM32F4xx_Nucleo_144/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I"C:/Users/lauta/Desktop/CESE/Materias/PdM/PdM_workspace/P4_ej2/Drivers/API" -I"C:/Users/lauta/Desktop/CESE/Materias/PdM/PdM_workspace/P4_ej2/Drivers/API/inc" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/lauta/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/BSP/STM32F4xx_Nucleo_144" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-STM32F4xx_Nucleo_144

clean-STM32F4xx_Nucleo_144:
	-$(RM) ./STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.cyclo ./STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.d ./STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.o ./STM32F4xx_Nucleo_144/stm32f4xx_nucleo_144.su

.PHONY: clean-STM32F4xx_Nucleo_144

