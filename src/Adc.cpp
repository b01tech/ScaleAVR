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

float Adc::calcFatorPesagem(float pesoConhecido)
{
    loadCell.calibrate_scale(pesoConhecido);
    return loadCell.get_scale();
}

void Adc::setFatorPesagem(float fatorPesagem)
{
    this->FatorPesagem = fatorPesagem;
};

void Adc::setFiltro(int filtro)
{
    this->Filtro = filtro;
}

float Adc::lerPeso()
{
    return loadCell.get_units(this->Filtro);
};

void Adc::getZero()
{
    loadCell.tare(5);
};

float Adc::getOffset()
{
    loadCell.tare(5);
    return loadCell.get_offset();
}

void Adc::saveConst(float zero, float span, float fator)
{
    this->ConstZero = zero;
    this->ConstSpan = span;
    this->FatorPesagem = fator;
}