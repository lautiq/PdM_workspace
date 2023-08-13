################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/src/API_SSD1306.c \
../Drivers/API/src/API_SSD1306_Fonts.c 

OBJS += \
./Drivers/API/src/API_SSD1306.o \
./Drivers/API/src/API_SSD1306_Fonts.o 

C_DEPS += \
./Drivers/API/src/API_SSD1306.d \
./Drivers/API/src/API_SSD1306_Fonts.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/src/API_SSD1306.o: ../Drivers/API/src/API_SSD1306.c Drivers/API/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/lauta/Desktop/CESE/Materias/PdM/PdM_workspace/TP_PCSE/Drivers/API/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/API/src/API_SSD1306_Fonts.o: ../Drivers/API/src/API_SSD1306_Fonts.c Drivers/API/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/lauta/Desktop/CESE/Materias/PdM/PdM_workspace/TP_PCSE/Drivers/API/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-src

clean-Drivers-2f-API-2f-src:
	-$(RM) ./Drivers/API/src/API_SSD1306.cyclo ./Drivers/API/src/API_SSD1306.d ./Drivers/API/src/API_SSD1306.o ./Drivers/API/src/API_SSD1306.su ./Drivers/API/src/API_SSD1306_Fonts.cyclo ./Drivers/API/src/API_SSD1306_Fonts.d ./Drivers/API/src/API_SSD1306_Fonts.o ./Drivers/API/src/API_SSD1306_Fonts.su

.PHONY: clean-Drivers-2f-API-2f-src

