#include "Headers/SerialPort.h"
#include <Arduino.h>

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
void SerialPort::enviarData() {}