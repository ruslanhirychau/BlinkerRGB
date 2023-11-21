#include "BlinkerRGB.h"

const int BlinkerRGB::DEFAULT_PULSES = 1;
const int BlinkerRGB::DEFAULT_PERIOD = 50;

BlinkerRGB::BlinkerRGB(int pin)
{
    _pin = pin;
    pinMode(_pin, OUTPUT);
    _pulses = DEFAULT_PULSES;
    _period = DEFAULT_PERIOD;
    _isOn = false;
    _previousMillis = 0;
    _blinkCount = 0;
}

void BlinkerRGB::blink(int pulses, int period, RGB color)
{
    _pulses = pulses;
    _period = period;
    _red = color.r;
    _green = color.g;
    _blue = color.b;
    _blinkCount = 0;
    _isOn = false;
    _previousMillis = millis();
}

void BlinkerRGB::blink(RGB color) { blink(DEFAULT_PULSES, DEFAULT_PERIOD, color); }

void BlinkerRGB::blink(int pulses, RGB color) { blink(pulses, DEFAULT_PERIOD, color); }

void BlinkerRGB::handle()
{
    if (_blinkCount < _pulses)
    {
        unsigned long currentMillis = millis();
        if (currentMillis - _previousMillis >= _period)
        {
            _previousMillis = currentMillis;

            if (_isOn)
            {
                neopixelWrite(_pin, 0, 0, 0);
                _isOn = false;
                _blinkCount++;
            }
            else
            {
                neopixelWrite(_pin, _red, _green, _blue);
                _isOn = true;
            }
        }
    }
}
