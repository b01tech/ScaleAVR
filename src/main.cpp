#include <Arduino.h>
#include "Headers/Scale.h"

Adc adc;
Display display;
Keypad keypad;
SerialPort serial;
Scale bal(adc, display, keypad, serial);

void setup()
{
  bal.zerar();
}

void loop()
{
}