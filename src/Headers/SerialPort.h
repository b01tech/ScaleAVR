#ifndef SERIALPORT_H
#define SERIALPORT_H

class SerialPort
{
private:
    int SerialMode;
    int Protocol;
    int BaudRate;

public:
    SerialPort();
    void setSerialMode(int);
    void setProtocol(int);
    void setBaudRate(int);
    void enviarData(float, int);
};

#endif