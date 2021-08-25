#include "Controller.h"
static const char *TAG = "Controller";

Controller *Controller::instance = 0;
Controller *Controller::getInstance()
{
    if (instance == 0)
    {
        instance = new Controller();
    }
    return instance;
}

Controller::Controller()
{
    TaskHandle_t timerTaskHandle = TaskHandles::getInstance()->getTimerHandle();
    TaskHandle_t timerStopTaskHandle = TaskHandles::getInstance()->getTimerStopHandle();

    xTaskCreatePinnedToCore(Controller::startTimerTask, "startTimerTask", 2000, (void *)this, 5, &timerTaskHandle, 0);
    xTaskCreatePinnedToCore(Controller::startTimerStopTask, "startTimerStopTask", 2000, (void *)this, 5, &timerStopTaskHandle, 0);
}

void Controller::startTimerTask(void *pvParameter)
{
    ((Controller *)pvParameter)->timerTask();
}

void Controller::timerTask()
{
    ESP_LOGI(TAG, "starting timer task");
    while (true)
    {
        ESP_LOGI(TAG, "timer increase task");
        vTaskDelay(1000);
    }
    vTaskDelete(NULL);
}

void Controller::startTimerStopTask(void *pvParameter)
{
    ((Controller *)pvParameter)->timerStopTask();
}

void Controller::timerStopTask()
{
    ESP_LOGI(TAG, "starting timer stop task");
    const long interval = 5000;
    while (true)
    {
        static long currentMillis = 0;
        //after five seconds I am trying to suspend the task
        if (millis() - currentMillis >= interval)
        {
            ESP_LOGI(TAG, "suspending");
            TaskHandle_t timerTaskHandle = TaskHandles::getInstance()->getTimerHandle();
            vTaskSuspend(timerTaskHandle);
        }
    }
    vTaskDelete(NULL);
}