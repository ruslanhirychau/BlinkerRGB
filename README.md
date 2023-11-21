# BlinkerRGB Arduino Library

## Description
The BlinkerRGB library is tailored for Arduino boards, offering a straightforward and efficient way to manage blinking patterns of built-in RGB LEDs. It employs non-blocking code, enabling the Arduino to perform other tasks while controlling the RGB LEDs. This library is particularly suited for projects requiring colorful LED notifications or indicators.

## Features
- Non-blocking RGB LED blinking
- Customizable number of blinks, blink duration, and color
- Easy integration into Arduino projects

## Installation
1. Download the library as a zip file.
2. Open the Arduino IDE, navigate to Sketch > Include Library > Add .ZIP Library, and select the downloaded zip file.
3. Once installed, include the BlinkerRGB library in your sketches with `#include <BlinkerRGB.h>`.

## Usage
Here's an example of using the BlinkerRGB library:

```cpp
#include <BlinkerRGB.h>

BlinkerRGB blinker; // Initialize with built-in LED pin

void setup() {
  blinker.blink(); // Default to 1 blink of 50ms in white color
}

void loop() {
  blinker.handle();
}
