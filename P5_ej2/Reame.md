# STM32F401 Nucleo Development Board - Anti-Bounce Button and LED Toggle

Este proyecto es una implementación en C para la placa de desarrollo STM32F401 Nucleo que utiliza el STM32 CubeIDE. 
La aplicación se basa en una máquina de estados finitos (FSM) anti-rebote para manejar el estado del botón y generar acciones en función de los flancos ascendentes y descendentes del botón. 
# Diferencia con el P4_ej1: 
- Se modularizo el funcionamiento de la maquina de estados, se puede encontrar dentro de 
/Project
|-- Drivers
    |-- API
        |-- src
        |-- inc

- Se implementa un LED2 (Led built-in) que cambia su frecuencia de parpadeo entre 100 ms y 500 ms cada vez que se presiona el botón.

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

Una vez que el firmware esté cargado en la placa, el LED2 comenzará a parpadear con una frecuencia de 100 ms. Cada vez que se presione el botón de usuario, la frecuencia cambiará a 500 ms. Puedes seguir presionando el botón para alternar entre estas dos frecuencias.


