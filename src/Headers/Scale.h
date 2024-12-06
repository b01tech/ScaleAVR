#ifndef SCALE_H
#define SCALE_H

// imports
#include "Adc.h"
#include "Display.h"
#include "Keypad.h"
#include "SerialPort.h"

class Scale
{
private:
    float PesoBruto;
    float Tara;
    float PesoLiquido;
    bool CalMode;
    bool FlagTara;

public:
    Scale(Adc &adc, Display &display, Keypad &keypad, SerialPort &serial);
    // Periféricos
    Adc &adc;
    Display &display;
    Keypad &keypad;
    SerialPort &serial;
    // Parametros
    int Divisao, PtoDecimal;
    float CapMaxima, Resolucao;
    // Métodos Calibração
    void setDivisao();
    void setPtoDecimal();
    void calcResolucao(int, int);
    void setCapMaxima();
    void setPesoConhecido();
    void setZero();
    void setSpan();
    void entrarCalibracao();
    void sairCalibracao();
    void salvarCalibracao();
    void initEEPROM();
    // Métodos Operação
    float pesar();
    void tarar();
    void zerar();
    void contarPecas();
    void checkLimites(float);
    bool lerZeroInicial();
    void buzzer();
    float setPeso();
};

#endif