#ifndef SERIALPORT_H
#define SERIALPORT_H

class SerialPort
{
private:
    int Protocol;
    int BaudRate;

public:
    SerialPort();
    int SerialMode;
    void setSerialMode(int);
    void setProtocol(int);
    void setBaudRate(int);
    void enviarData(float, int);
};

#endif