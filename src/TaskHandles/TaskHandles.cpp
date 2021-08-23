#include "TaskHandles.h"

static const char *TAG = "GPS";

TaskHandles *TaskHandles::instance = 0;
TaskHandles *TaskHandles::getInstance()
{
    if (instance == 0)
    {
        instance = new TaskHandles();
    }
    return instance;
}

TaskHandles::TaskHandles()
{
    ESP_LOGI(TAG, ">>");
    ESP_LOGI(TAG, "<<");
}

xTaskHandle TaskHandles::getTimerHandle()
{
    ESP_LOGI(TAG, ">>");
    if (timerHandle == nullptr)
    {
        ESP_LOGI(TAG, "creating new timer handle");
        timerHandle = new xTaskHandle();
    }
    ESP_LOGI(TAG, "<<");
    return timerHandle;
}

xTaskHandle TaskHandles::getTimerStopHandle()
{
    if (timerStopHandle == nullptr)
    {
        ESP_LOGI(TAG, "creating new timer stop handle");
        timerStopHandle = new xTaskHandle();
    }

    return timerStopHandle;
}
