#include <Arduino.h>    // Include Arduino main library
#include <BlinkerRGB.h> // Include custom BlinkerRGB library for LED control

// BlinkerRGB blinker; // Create a BlinkerRGB object for an LED connected to default pin
BlinkerRGB blinker(38); // Create a BlinkerRGB object for an LED connected to pin 38

void setup()
{
  blinker.blink(3); // Set the LED to blink 3 times at startup
}

void loop()
{
  blinker.handle(); // Continuously update the LED state

  // Logic to blink the LED every second
  static unsigned long previousMillis = millis(); // Remember the last time the LED was updated

  // Check if 1 second has passed
  if (millis() - previousMillis >= 1000)
  {
    blinker.blink(RGB{0, 255, 0}); // Blink the LED in green color
    previousMillis = millis();     // Reset the timer
  }
}
