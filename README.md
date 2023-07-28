# PdM_workspace

# Descripción
PdM_workspace es un repositorio multiproyectos de codigo abierto realizado para la carrera de especializacion en sistemas embebidos de la UBA. 
Aqui se encontrarán las diferentes resoluciones a los ejercicios de la materia Programacion de Microcontroladores.

# Caracteristicas claves
Prácticos resueltos en una placa STM32-F401. 
Se agregó la carpeta STM32F4xx_Nucleo_144 para poder hacer uso de las funciones BSP. 
Se modificó la libreria stm32f4xx_nucleo_144.h para poder utilizar dos LEDs externos y realizar la practica con ellos mas el led de la placa. 
En las definiciones de los pines se observa: 
- LED1: LED externo conectado en GPIO_PIN_6
- LED2: LED de la placa llamado LD2 correspondiente a GPIO_PIN_5
- LED3: LED externo conectado en GPIO_PIN_7

## Dependencias

- STM32 CubeIDE
- STM32F401 Nucleo Board (u otra compatible)
- STM32 HAL Library

## Estructura del Repositorio
 
/Project
|-- .cproject
|-- .project
|-- .settings
|-- Drivers
|-- Inc
|-- Middlewares
|-- Src
|-- .gitignore
|-- README.md


## Configuración del Proyecto

1. Clona el repositorio o descarga los archivos en tu sistema local.
2. Abre STM32 CubeIDE y selecciona "Importar proyecto existente" desde el menú "File".
3. Navega hasta el directorio donde clonaste o descargaste el repositorio y selecciona la carpeta "Project".
4. Sigue las instrucciones del asistente para importar el proyecto.
5. Conecta la placa STM32F401 Nucleo a tu computadora y configura la conexión de depuración y compilación.
6. Compila el proyecto y carga el firmware en la placa.

## Uso

dependerá del ejercicio!
