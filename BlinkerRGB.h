#ifndef BlinkerRGB_h
#define BlinkerRGB_h

#include <Arduino.h>

class BlinkerRGB
{
public:
    BlinkerRGB(int pin = LED_BUILTIN);
    void init();
    void blink(int pulses = 1, int period = 50);
    void handle();

private:
    int _pin;
    int _pulses;
    int _period;
    bool _isOn;
    unsigned long _previousMillis;
    int _blinkCount;
};

#endif
