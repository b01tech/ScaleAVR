#ifndef ADC_H
#define ADC_H

class Adc
{
private:
    float Peso;
    int Filtro;

public:
    Adc();
    Adc(float);
    float FatorPesagem;
    float ConstZero, ConstSpan;
    float calcFatorPesagem(float);
    void setFatorPesagem(float);
    void setFiltro(int);
    float getOffset();
    float lerPeso();
    void getZero();
    void saveConst(float z, float s, float f);
};

#endif