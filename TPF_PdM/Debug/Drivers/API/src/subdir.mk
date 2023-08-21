################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/src/API_SSD1306.c \
../Drivers/API/src/API_SSD1306_Fonts.c \
../Drivers/API/src/API_chronos.c \
../Drivers/API/src/API_debounce.c \
../Drivers/API/src/API_delay.c \
../Drivers/API/src/API_uart.c 

OBJS += \
./Drivers/API/src/API_SSD1306.o \
./Drivers/API/src/API_SSD1306_Fonts.o \
./Drivers/API/src/API_chronos.o \
./Drivers/API/src/API_debounce.o \
./Drivers/API/src/API_delay.o \
./Drivers/API/src/API_uart.o 

C_DEPS += \
./Drivers/API/src/API_SSD1306.d \
./Drivers/API/src/API_SSD1306_Fonts.d \
./Drivers/API/src/API_chronos.d \
./Drivers/API/src/API_debounce.d \
./Drivers/API/src/API_delay.d \
./Drivers/API/src/API_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/src/%.o Drivers/API/src/%.su Drivers/API/src/%.cyclo: ../Drivers/API/src/%.c Drivers/API/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/lauta/Desktop/CESE/Materias/PdM/PdM_workspace/TPF_PdM/Drivers/API/inc" -I"C:/Users/lauta/Desktop/CESE/Materias/PdM/PdM_workspace/TPF_PdM/STM32F4xx_Nucleo_144" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-src

clean-Drivers-2f-API-2f-src:
	-$(RM) ./Drivers/API/src/API_SSD1306.cyclo ./Drivers/API/src/API_SSD1306.d ./Drivers/API/src/API_SSD1306.o ./Drivers/API/src/API_SSD1306.su ./Drivers/API/src/API_SSD1306_Fonts.cyclo ./Drivers/API/src/API_SSD1306_Fonts.d ./Drivers/API/src/API_SSD1306_Fonts.o ./Drivers/API/src/API_SSD1306_Fonts.su ./Drivers/API/src/API_chronos.cyclo ./Drivers/API/src/API_chronos.d ./Drivers/API/src/API_chronos.o ./Drivers/API/src/API_chronos.su ./Drivers/API/src/API_debounce.cyclo ./Drivers/API/src/API_debounce.d ./Drivers/API/src/API_debounce.o ./Drivers/API/src/API_debounce.su ./Drivers/API/src/API_delay.cyclo ./Drivers/API/src/API_delay.d ./Drivers/API/src/API_delay.o ./Drivers/API/src/API_delay.su ./Drivers/API/src/API_uart.cyclo ./Drivers/API/src/API_uart.d ./Drivers/API/src/API_uart.o ./Drivers/API/src/API_uart.su

.PHONY: clean-Drivers-2f-API-2f-src

