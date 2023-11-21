#ifndef BlinkerRGB_h
#define BlinkerRGB_h

#include <Arduino.h>
// #include <NeoPixel.h>

struct RGB
{
    byte r, g, b;
    RGB(byte red = 255, byte green = 255, byte blue = 255) : r(red), g(green), b(blue) {}
};

class BlinkerRGB
{
public:
    static const int DEFAULT_PULSES;
    static const int DEFAULT_PERIOD;
    BlinkerRGB(int pin = RGB_BUILTIN);
    void init();
    void blink(RGB color);
    void blink(int pulses, RGB color);
    void blink(int pulses = DEFAULT_PULSES, int period = DEFAULT_PERIOD, RGB color = RGB());
    void handle();

private:
    int _pin;
    int _pulses;
    int _period;
    bool _isOn;
    unsigned long _previousMillis;
    int _blinkCount;
    byte _red, _green, _blue;
};

#endif
