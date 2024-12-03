#ifndef ADC_H
#define ADC_H

class Adc
{
private:
    float FatorPesagem;
    float ConstZero, ConstSpan;
    float Peso;

public:
    Adc();
    float setFatorPesagem();
    float lerPeso();
    void getZero();
};

#endif