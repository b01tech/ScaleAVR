#include "Headers/SerialPort.h"
#include <Arduino.h>

void ProtocoloDG(float peso, int ptoDecimal);
char calcStatusDG(float peso);

SerialPort::SerialPort()
{
    Serial.begin(this->BaudRate);
}

void SerialPort::setSerialMode(int mode = 0)
{
    this->SerialMode = mode;
}

void SerialPort::setProtocol(int protocol = 0)
{
    this->Protocol = protocol;
}

void SerialPort::setBaudRate(int baud = 9600)
{
    this->BaudRate = baud;
}

void SerialPort::enviarData(float peso, int ptoDecimal)
{
    switch (this->Protocol)
    {
    case 0: // NONE
        break;
    case 1: // DGN
        ProtocoloDG(peso, ptoDecimal);
        break;
    default:
        setProtocol(0);
        break;
    }
    delay(250);
}

void ProtocoloDG(float peso, int ptoDecimal)
{
    String pesoFormatado;

    char status = calcStatusDG(peso);

    if (peso < 0.0f)
    {
        peso *= -1; // Converter peso para positivo para formatação
    }

    pesoFormatado = String(peso, ptoDecimal);
    while (pesoFormatado.length() < 7)
    {
        pesoFormatado = "0" + pesoFormatado;
    }

    Serial.print(status);
    Serial.print(pesoFormatado);
    Serial.print(String(char(0x0D)));

    delay(20);
}

char calcStatusDG(float peso)
{
    char status = '\0';

    if (peso == 0.0f)
    {
        status = 'F'; // Peso em zero
    }
    else if (peso < 0.0f)
    {
        status = 'H'; // Peso negativo
    }
    else if (peso > 0.0f)
    {
        status = 'D'; // Peso positivo
    }
    else
    {
        status = '@'; // Em movimento
    }
    return status;
}