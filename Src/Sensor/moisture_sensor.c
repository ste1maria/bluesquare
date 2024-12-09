#include "main.h"
#include "moisture_sensor.h"

static void SensorStart();
static void SensorStop();
static uint32_t ReadMoisture();

extern ADC_HandleTypeDef hadc1;

uint32_t GetMoisture()
{
    uint32_t result = 0U;
    SensorStart();
    result = ReadMoisture();
    SensorStop();
    return result;
}

void SensorStart()
{
    HAL_ADC_Start(&hadc1);
}

uint32_t ReadMoisture()
{
    uint32_t sensorReading = 0;
    if (HAL_ADC_PollForConversion(&hadc1, 1000U))
    {
        sensorReading = HAL_ADC_GetValue(&hadc1);
    }
    return sensorReading;
}

void SensorStop()
{
    HAL_ADC_Stop(&hadc1);
}