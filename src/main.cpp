#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "Headers/Scale.h"

Adc adc;
Display display;
Keypad keypad;
SerialPort serial;
Scale bal(adc, display, keypad, serial);

void Task_Pesagem(void *param);
void Task_Teclado(void *param);
void Task_Serial(void *param);

TaskHandle_t TaskHandle_Pesagem;
TaskHandle_t TaskHandle_Teclado;
TaskHandle_t TaskHandle_Serial;

void setup()
{
  xTaskCreate(Task_Teclado, "Task_Teclado", 100, NULL, 3, &TaskHandle_Teclado);
  xTaskCreate(Task_Pesagem, "Task_Pesagem", 100, NULL, 2, &TaskHandle_Pesagem);
  xTaskCreate(Task_Serial, "Task_Serial", 100, NULL, 1, &TaskHandle_Serial);
}

void loop()
{
}

void Task_Pesagem(void *param)
{
  float peso;
  while (1)
  {
    peso = bal.pesar();
    bal.display.exibirPeso(peso);

    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void Task_Teclado(void *param)
{
  char tecla;
  while (1)
  {
    tecla = bal.keypad.lerTecla();
    switch (tecla)
    {
    case 'T':
      bal.tarar();
      break;
    case 'Z':
      bal.zerar();
      break;
    case 'L':
      bal.display.navegarMenu();
      break;
    case 'I':
      if (bal.serial.SerialMode == 0)
      {
        bal.serial.enviarData(bal.adc.lerPeso(), bal.PtoDecimal);
      }
      break;
    default:
      break;
    }
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void Task_Serial(void *param)
{
  while (1)
  {
    if (bal.serial.SerialMode == 1)
    {
      bal.serial.enviarData(bal.adc.lerPeso(), bal.PtoDecimal);
    }
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}