# Generative Art
This project is a blend of technology and art, creating a dynamic display of love poems and heart shapes on a TFT display. It's built using Arduino and leverages the power of the TFT_eSPI and Adafruit_ILI9341 libraries to control the TFT display.

![](https://github.com/aryanamoh/generative-art/blob/main/mod1-ttgoscreen.gif)

## Features
- <b>Dynamic Display:</b> The project continuously generates and displays heart shapes of varying sizes and colors at random positions on the screen. The colors range from vivid pink to light coral, creating a visually appealing effect.

- <b>Love Poems:</b> Alongside the heart shapes, the display also shows love poems randomly selected from a pre-defined array. A new poem is selected and displayed every 10 seconds.

- <b>Hardware Control:</b> The project uses the SPI protocol to communicate with the TFT display. The display's backlight brightness is also programmatically controlled.


## Code Overview 
The code is divided into two main parts: the `setup()` function and the `loop()` function.

- The `setup()` function initializes the TFT display, sets the rotation, fills the screen with black color, sets the text color to white, and adjusts the screen backlight brightness.
- The `loop()` function is where the bulk of the display generation happens. It continuously clears the screen, generates a random size and location for the heart, draws the heart with a random color from the predefined color list, and displays a randomly selected poem from the array of love poems.


## How to Run 
To run this project, you need to have the Arduino IDE installed on your computer. 

1. Open the `generative-art.ino` file in the Arduino IDE. 
2. Ensure all required libraries (listed below) are installed. 
3. Connect your Arduino board with the TFT display to your computer, selecting the correct port and board (in this case, the TTGO T1).
4. Upload the code to the board.


## Dependencies 
This project depends on the following libraries:
- [Adafruit ILI9341 Library](https://github.com/adafruit/Adafruit_ILI9341) (built with version 1.6.0)
- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library) (built with version 1.11.9)
- [TFT_eSPI Library](https://github.com/Bodmer/TFT_eSPI) (built with version 2.5.34)

These libraries need to be installed in your Arduino IDE before running the project.

## About
- Author: Aryana Mohammadi
- Built with Arduino IDE version 2.3.0, CLI Version: 0.35.2
- Displayed on a ESP32 TTGO T-Display
- Updated February 12, 2024
