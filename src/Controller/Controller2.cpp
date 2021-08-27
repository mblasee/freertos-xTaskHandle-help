#include "Controller2.h"
static const char *TAG = "Controller";

Controller2 *Controller2::instance = 0;
Controller2 *Controller2::getInstance()
{
    if (instance == 0)
    {
        instance = new Controller2();
    }
    return instance;
}

Controller2::Controller2()
{
    xTaskCreatePinnedToCore(Controller2::startTimerTask, "startTimerTask", 2000, (void *)this, 5, &controllerTask, 1);
    vTaskSuspend(controllerTask);
}

void Controller2::startTimerTask(void *pvParameter)
{
    ((Controller2 *)pvParameter)->timerTask();
}

void Controller2::timerTask()
{
    ESP_LOGI(TAG, "starting timer task2");
    while (true)
    {
        ESP_LOGI(TAG, "timer increase task2");
        vTaskDelay(1000);
    }
    vTaskDelete(controllerTask);
}

void Controller2::stopTask()
{
    ESP_LOGI(TAG, "stopping timer task2");
    vTaskSuspend(controllerTask);
}

void Controller2::startTask()
{
    ESP_LOGI(TAG, "resuming timer task2");
    vTaskResume(controllerTask);
}