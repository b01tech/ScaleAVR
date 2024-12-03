#include "Headers/Scale.h"

Scale::Scale(Adc &adc, Display &display, Keypad &keypad, SerialPort &serial)
    : adc(adc), display(display), keypad(keypad), serial(serial)
{
}

void Scale::zerar()
{
    if (this->PesoLiquido > 0.1)
    {
        adc.getZero();
    }
}