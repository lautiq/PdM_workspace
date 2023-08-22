# Chronometer APP 

![Chronometer]![image](https://github.com/lautiq/PdM_workspace/assets/110248182/9d09d5b7-bcfd-4295-9b74-b4dfacc27400)

This repository contains the firmware for the Chronometer APP, developed as the final project for the "PdM" course at [UBA]. The system includes an SSD1306 OLED display and implements a Finite State Machine (FSM) to control the chronometer's functionalities.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Hardware](#hardware)
- [Dependencies](#dependencies)
- [Usage](#usage)
- [Directory Structure](#directory-structure)
- [FSM Description](#fsm-description)
- [Contributing](#contributing)
- [Credits](#credits)

## Overview

The Chronometer APP combines an SSD1306 OLED display driver and a Finite State Machine (FSM) implementation to provide a versatile and user-friendly chronometer solution. The system is developed using STM32 microcontrollers and is aimed at showcasing best programming practices and encapsulation principles.

## Features

- Implementation of an FSM to manage chronometer functionalities.
- Encapsulation of functionalities into modular API files.
- Clear and concise API interface for controlling the chronometer system.
- Compatibility with STM32 microcontrollers.
- Utilization of an SSD1306 OLED display for visual feedback.

## Hardware

To use this system, you'll need the following components:

- STM32 microcontroller (e.g., STM32F401RE)
- SSD1306 OLED display
- 3 Buttons.

## Dependencies

- STM32 CubeIDE
- STM32 HAL Library

## Usage

1. Clone or download this repository to your STM32 project directory.
2. Include the necessary files in your project.
3. Initialize the system using the provided APIs.
4. Implement your application logic while utilizing the chronometer functionalities and OLED display.

   Example code:
```c
#include "API_chronos.h"
#include "API_SSD1306.h"
#include "API_chronos.h"

int main(void)
{
  HAL_Init();
  // Initialize hardware and peripherals

  chronosFSM_init();

while (1)
{
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
	 // Update debounce FSM
	  debounceFSM_update(&btn1);
	  debounceFSM_update(&btn2);
	  debounceFSM_update(&btn3);

	  // Get button states
    bool_t btn1Pressed = readButton(&btn1);
    bool_t btn2Pressed = readButton(&btn2);
    bool_t btn3Pressed = readButton(&btn3);


    // Update chronometer
	  chronosFSM_update(btn1Pressed, btn2Pressed, btn3Pressed);
}
/* USER CODE END 3 */
}
 ```

Directory Structure
css
Copy code
.
├── core
│      ├── inc
│      │     └── main.h
│      └── src
│            └── main.c
├── drivers
│   └──API
│      ├── inc
│      │     └── API_chronos.h
│      │     └── API_debounce.h
│      │     └── API_delay.h
│      │     └── API_SSD1306.h
│      │     └── API_SSD1306_Fonts.h
│      └── src
│            └── API_chronos.c
│            └── API_debounce.c
│            └── AAPI_delay.c
│            └── API_SSD1306.c
│            └── API_SSD1306_Fonts.c
├── examples
│   └── main.c
└── README.md  



# FSM Description
The Finite State Machine (FSM) implemented in API_chronos.c manages the behavior of the chronometer based on button inputs. It transitions between different states to control the start, pause, resume, and stop functionalities.

States:

Init State: The initial state where the chronometer is not running. Instructions for button functions are displayed on the OLED screen.

Start State: When the "Start" button is pressed, the chronometer transitions to this state. It starts counting time from zero and displays the elapsed time on the OLED screen.

Pause State: Pressing the "Pause" button in the "Start" state leads to this state. The elapsed time is frozen, and the paused time is displayed on the screen. The user can choose to resume or stop the chronometer from this state.

Resume State: Upon pressing the "Resume" button in the "Pause" state, the chronometer enters this state. The chronometer resumes counting time, adding the paused time to the total elapsed time. The OLED screen displays the updated elapsed time.

Stop State: When the "Stop" button is pressed in any active state, the chronometer enters this state. The final elapsed time (or paused time if stopped from the "Pause" state) is displayed on the OLED screen.

Transitions and Functionality:

In the "Init" state, the "Start" button transitions to the "Start" state, initializing the chronometer's start time.
In the "Start" state, the "Pause" button pauses the chronometer, saving the current elapsed time. The "Stop" button stops the chronometer.
In the "Pause" state, the "Resume" button resumes the chronometer from where it was paused. The "Stop" button stops the chronometer.
In the "Resume" state, the "Pause" button pauses the chronometer again, saving the resumed time. The "Stop" button stops the chronometer.
In the "Stop" state, the "Start" button resets the chronometer, returning to the "Init" state.
This FSM architecture ensures smooth and intuitive control of the chronometer's functionality through various states and button interactions.

Contributing
Contributions to this project are welcome. If you find any issues or want to improve the driver, feel free to open an issue or submit a pull request.

Credits
This project was developed by [Lautaro Quarin] as part of the [PdM] course at [UBA].
