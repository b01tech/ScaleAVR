#ifndef SERIAL_H
#define SERIAL_H

class Serial
{
private:
    int SerialMode;
    int Protocol;

public:
    Serial();
    void setSerialMode(int);
    void setProtocol(int);
    void enviarData();
};

#endif