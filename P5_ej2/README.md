# STM32F401 Nucleo Development Board - UART API 

Este proyecto es una implementación en C para la placa de desarrollo STM32F401 Nucleo que utiliza el STM32 CubeIDE. 

Se utilizo la API creada para la practica 5 ejercicio 1, combinando con la practica 4 (MEF), se tiene una programa
que cambia la frecuencia de parpadeo del led interno de la placa, a su vez se informa mediante UART cuando se 
detecta un flanco ascendente y uno descendente.



Al probar este programa se inicializa la uart y se recibirá el siguiente mensaje si esta todo bien:
![image](https://github.com/lautiq/PdM_workspace/assets/110248182/68ec514f-6f0d-49ed-bb89-ae42ab9be05b)

Y al presionar el boton se deben ver los mensajes siguientes respecto al estado del boton.
![image](https://github.com/lautiq/PdM_workspace/assets/110248182/032e70ae-ecaa-48a2-882b-e6d8e7d90f67)




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


