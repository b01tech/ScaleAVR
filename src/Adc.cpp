#include "Headers/Adc.h"
#include <HX711.h>

#define pinDT A1
#define pinSCK A0

HX711 loadCell;

Adc::Adc()
{
    float fatorPesagem = 213900.0f;
    loadCell.begin(pinDT, pinSCK);
    loadCell.set_scale(fatorPesagem);
    loadCell.power_up();
    loadCell.tare();
};

Adc::Adc(float fatorPesagem = 213900.0f)
{
    loadCell.begin(pinDT, pinSCK);
    loadCell.set_scale(fatorPesagem);
    loadCell.power_up();
    loadCell.tare();
};

void Adc::setFatorPesagem(float pesoConhecido)
{
    float span = loadCell.get_units(5);
    this->ConstSpan = span;
    loadCell.calibrate_scale(pesoConhecido);
    this->FatorPesagem = loadCell.get_scale();
};

float Adc::lerPeso(int filtro = 6)
{
    return loadCell.get_units(filtro);
};

void Adc::getZero()
{
    loadCell.tare(5);
};
