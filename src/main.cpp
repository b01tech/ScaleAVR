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
  while (1)
  {
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void Task_Teclado(void *param)
{
  while (1)
  {
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void Task_Serial(void *param)
{
  while (1)
  {
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}