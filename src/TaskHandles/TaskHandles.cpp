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
    //if these are uncommented I get the very same exception but this way I am just returning nullptrs
    //timerHandle = new TaskHandle_t();
    //timerStopHandle = new TaskHandle_t();
    ESP_LOGI(TAG, "<<");
}

TaskHandle_t TaskHandles::getTimerHandle()
{
    return timerHandle;
}

TaskHandle_t TaskHandles::getTimerStopHandle()
{
    return timerStopHandle;
}