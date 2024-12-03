#ifndef ADC_H
#define ADC_H

class Acd
{
private:
    float FatorPesagem;
    float ConstZero, ConstSpan;
    float Peso;

public:
    Acd();
    float setFatorPesagem();
    float lerPeso();
    float getZero();
};

#endif