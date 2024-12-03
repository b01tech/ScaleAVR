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
    Adc(float);
    void setFatorPesagem(float);
    float lerPeso(int);
    void getZero();
};

#endif