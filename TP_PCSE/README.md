# SSD1306 OLED Driver for STM32

![OLED Display 128x64](https://github.com/lautiq/PdM_workspace/assets/110248182/1b9091c5-a636-41e7-ba5c-13f7742862a1)

This repository contains a driver for controlling SSD1306 OLED displays on the STM32F401RE microcontroller. The driver is designed for the final project for the asignature "PCSE". 

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Hardware](#hardware)
- [Usage](#usage)
- [Directory Structure](#directory-structure)
- [Functions Description](#function-description)
- [Contributing](#contributing)


## Overview

This SSD1306 OLED driver provides an easy-to-use interface for interacting with SSD1306-based OLED displays using the STM32F401RE microcontroller. The driver is written in C and is contained in the "API" folder of the "Drivers" directory.

## Features

- Initialization and configuration of SSD1306 OLED displays.
- Displaying text and graphics on the OLED screen.
- Simple and clear API for interfacing with the display.
- Optimized for the STM32F401RE microcontroller.

## Hardware

In order to use this project you will need the following components:

- STM32F401RE microcontroller
- SSD1306 OLED display

## Usage

1. Clone or download this repository to your STM32 project directory.
2. Include the necessary files in your project.
3. Initialize the OLED display using "oledInit()" Function
4. Use the provided functions to control and display content on the OLED screen.

   Example code:
```c
#include "API_SSD1306.h"

int main(void)
{
  HAL_Init();
  //Initialize hardware and peripherals

  oledInit();
  oledSetCursor(0,0);
  oledWriteString("Hello, OLED!", White);

  while(1)
  {
  //Your main application logic here
  }
}
```

# Directory Structure

```css
.
├── drivers
│   ├── API
│   │   ├── inc
│   │   │   └── API_SSD1306.h
│   │   └── src
│   │       └── API_SSD1306.c
│   └── images
│       ├── oled_display.jpg
│       └── circuit_diagram.png
├── examples
│   └── main.c
└── README.md

```

# Functions Description

1. WriteCommand(uint8_t byte)
    This function sends a command to the SSD1306 controller through the I2C bus. It is internally used to send various commands to configure display modes and parameters.
2. WriteData(uint8_t* buffer, size_t buff_size)
Transmits data to the SSD1306 controller using the I2C bus. It is employed to send image data to the controller, allowing for dynamic updates of the display content.

3. ssd1306_Init()
Initializes the SSD1306 OLED display. It configures various display parameters and options to prepare the display for use. Clears the screen and sets the cursor position to (0,0).

4. ssd1306_Fill(SSD1306_COLOR color)
Fills the display buffer with a specified color. This can be used to clear the screen or fill it with a desired color.

5. ssd1306_UpdateScreen()
Updates the display with the content stored in the buffer. Writes the buffer data to the display's RAM pages, resulting in visible changes on the screen.

6. ssd1306_DrawPixel(uint8_t x, uint8_t y, SSD1306_COLOR color)
Draws a single pixel at a specific position on the screen with the specified color. Useful for creating images and patterns on the OLED screen.

7. ssd1306_WriteChar(char character, SSD1306_COLOR color)
Writes a character to the display at the current cursor position. Used for displaying text on the OLED screen with the chosen color.

8. ssd1306_WriteString(char* string, SSD1306_COLOR color)
Writes a string of characters to the display at the current cursor position. Useful for displaying longer text on the OLED screen with the desired color.

9. ssd1306_SetCursor(uint8_t x, uint8_t y)
Sets the cursor position on the display. Writing functions for characters and strings use this position as a reference to display content.

These functions collectively allow you to control and manipulate the SSD1306 OLED display, enabling you to display text, images, and other graphics on the screen.

# Contributing 

Contributions to this project are welcome. If you find any issues or want to improve the driver, feel free to open an issue or submit a pull request.



