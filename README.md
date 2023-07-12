# PdM_workspace

Prácticos resueltos en una placa STM32-F401. 
Se agregó la carpeta STM32F4xx_Nucleo_144 para poder hacer uso de las funciones BSP. 
Se modificó la libreria stm32f4xx_nucleo_144.h para poder utilizar dos LEDs externos y realizar la practica con ellos mas el led de la placa. 
En las definiciones de los pines se observa: 
LED1 -> LED externo conectado en GPIO_PIN_6
LED2 -> LED de la placa llamado LD2 correspondiente a GPIO_PIN_5
LED3 -> LED externo conectado en GPIO_PIN_7
