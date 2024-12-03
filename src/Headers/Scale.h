#ifndef SCALE_H
#define SCALE_H
class Scale
{
private:
    int Divisao, PtoDecimal;
    float CapMaxima, Resolucao;
    float PesoConhecido;
    float PesoBruto;
    float Tara;
    float PesoLiquido;
    bool CalMode;
    bool FlagTara;

public:
    Scale();
    // Calibração
    void setDivisao(int);
    void setPtoDecimal(int);
    void calcResolucao(int);
    void setCapMaxima(float);
    void setPesoConhecido(float);
    void entrarCalibracao();
    void sairCalibracao();
    void salvarCalibracao(bool);
    void initEEPROM();
    // Operação
    void tarar();
    void zerar();
    void contarPecas();
    void checkLimites(float);
    bool lerZeroInicial();
    void buzzer();
};

#endif