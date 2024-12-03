#include "Headers/Keypad.h"
#include <Arduino.h>

#define PIN_COMUM 5
#define PIN_T 6
#define PIN_L 7
#define PIN_Z 8
#define PIN_I 9

Keypad::Keypad()
{
    pinMode(PIN_T, INPUT_PULLUP);
    pinMode(PIN_L, INPUT_PULLUP);
    pinMode(PIN_Z, INPUT_PULLUP);
    pinMode(PIN_I, INPUT_PULLUP);
}

char Keypad::lerTecla()
{
    if (digitalRead(PIN_T) == LOW)
    {
        return 'T';
    }
    if (digitalRead(PIN_L) == LOW)
    {
        return 'L';
    }
    if (digitalRead(PIN_Z) == LOW)
    {
        return 'Z';
    }
    if (digitalRead(PIN_I) == LOW)
    {
        return 'I';
    }

    delay(100);
}

float Keypad::setParam()
{
}