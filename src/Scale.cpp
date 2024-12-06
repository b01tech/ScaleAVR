#include "Headers/Scale.h"
#include <math.h>
#include <Arduino.h>
#include <EEPROM.h>
struct Cal
{
    int tempDivisao, tempPtoDecimal;
    float tempCapMaxima, tempPesoCal, tempZero, tempSpan, tempFator;
} tempCal;

Scale::Scale(Adc &adc, Display &display, Keypad &keypad, SerialPort &serial)
    : adc(adc), display(display), keypad(keypad), serial(serial)
{
    this->FlagTara = false;
}

void Scale::zerar()
{
    if (this->PesoLiquido > 0.1)
    {
        adc.getZero();
    }
}

void Scale::tarar()
{
    this->FlagTara = !this->FlagTara;
    if (this->FlagTara)
    {
        this->Tara = adc.lerPeso();
    }
    else
    {
        this->Tara = 0.0f;
    }
}

float Scale::pesar()
{
    this->PesoBruto = adc.lerPeso();
    this->PesoLiquido = this->PesoBruto - this->Tara;
    return this->PesoLiquido;
}

void Scale::entrarCalibracao()
{
    // Sequência: divisão(1), casas decimais(2), cap. max(3), peso cal(4), zero(5), span(6), salvar(7)
    setDivisao();
    setPtoDecimal();
    setCapMaxima();
    setPesoConhecido();
    setZero();
    setSpan();
    sairCalibracao();
}

void Scale::setDivisao()
{
    display.exibirMensagem("divisao");
    tempCal.tempDivisao = keypad.setParamInt();
}

void Scale::setPtoDecimal()
{
    display.exibirMensagem("ptodecimal");
    tempCal.tempPtoDecimal = keypad.setParamInt();
}

void Scale::calcResolucao(int divisao, int ptoDecimal)
{
    this->Resolucao = (float)divisao / pow(10, ptoDecimal);
}

void ::Scale::setCapMaxima()
{
    display.exibirMensagem("capMaxima");
    tempCal.tempCapMaxima = keypad.setParamFloat();
}

void Scale::setPesoConhecido()
{
    display.exibirMensagem("pesoConhecido");
    tempCal.tempPesoCal = keypad.setParamFloat();
}

void Scale::setZero()
{
    display.exibirMensagem("zero");
    char tecla;
    adc.getZero();
    do
    {
        tecla = keypad.lerTecla();
        tempCal.tempZero = adc.getOffset();
        display.exibirPeso(tempCal.tempZero);
        delay(100);
    } while (tecla != 'T');
}

void Scale::setSpan()
{
    display.exibirMensagem("span");
    char tecla;
    do
    {
        tecla = keypad.lerTecla();
        tempCal.tempSpan = adc.lerPeso();
        float percentADC = (tempCal.tempSpan / tempCal.tempCapMaxima) * 100;
        display.exibirPeso(percentADC);
        delay(100);

    } while (tecla != 'T');
    tempCal.tempFator = adc.calcFatorPesagem(tempCal.tempPesoCal);
}

void Scale::salvarCalibracao()
{
    this->Divisao = tempCal.tempDivisao;
    this->PtoDecimal = tempCal.tempPtoDecimal;
    calcResolucao(Divisao, PtoDecimal);
    this->CapMaxima = tempCal.tempCapMaxima;
    adc.saveConst(tempCal.tempZero, tempCal.tempSpan, tempCal.tempFator);
}

void Scale::sairCalibracao()
{
    char tecla;
    do
    {
        display.exibirMensagem("saveCal");

    } while (tecla != 'T' && tecla != 'Z');
    if (tecla == 'T')
    {
        salvarCalibracao();
    }
    else if (tecla == 'Z')
    {
        entrarCalibracao();
    }
}

void Scale::initEEPROM()
{
    int address = 0;
    EEPROM.get(address, Divisao);
    address += sizeof(Divisao);
    EEPROM.get(address, PtoDecimal);
    address += sizeof(PtoDecimal);
    EEPROM.get(address, CapMaxima);
    address += sizeof(CapMaxima);
    EEPROM.get(address, adc.ConstZero);
    address += sizeof(adc.ConstZero);
    EEPROM.get(address, adc.ConstSpan);
    address += sizeof(adc.ConstSpan);
    EEPROM.get(address, adc.FatorPesagem);

    if (this->adc.FatorPesagem == 0xFFFFFFFF)
    {
        Divisao = 1;
        PtoDecimal = 1;
        CapMaxima = 10.0f;
        adc.FatorPesagem = 213900.0f;
    }
}