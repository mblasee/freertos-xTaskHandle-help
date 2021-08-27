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
    xTaskCreatePinnedToCore(Controller::startTimerTask, "startTimerTask", 2000, (void *)this, 5, &controllerTask, 1);
    vTaskSuspend(controllerTask);
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
    vTaskDelete(controllerTask);
}

void Controller::stopTask()
{
    ESP_LOGI(TAG, "stopping timer task");
    vTaskSuspend(controllerTask);
}

void Controller::startTask()
{
    ESP_LOGI(TAG, "resuming timer task");
    vTaskResume(controllerTask);
}

/*
log output example
[I][Controller.cpp:44] startTask(): resuming timer task
[I][Controller.cpp:27] timerTask(): starting timer task
[I][Controller.cpp:30] timerTask(): timer increase task
[I][Controller.cpp:30] timerTask(): timer increase task
[I][Controller.cpp:30] timerTask(): timer increase task
[I][Controller.cpp:30] timerTask(): timer increase task
[I][Controller.cpp:30] timerTask(): timer increase task
[I][main.cpp:26] loop(): suspending
[I][Controller.cpp:38] stopTask(): stopping timer task
[I][Controller2.cpp:27] timerTask(): starting timer task2
[I][Controller2.cpp:30] timerTask(): timer increase task2
[I][Controller2.cpp:44] startTask(): resuming timer task2
[I][Controller2.cpp:30] timerTask(): timer increase task2
[I][Controller2.cpp:30] timerTask(): timer increase task2
[I][Controller2.cpp:30] timerTask(): timer increase task2
[I][Controller2.cpp:30] timerTask(): timer increase task2
[I][Controller2.cpp:30] timerTask(): timer increase task2
[I][main.cpp:34] loop(): resuming
[I][Controller.cpp:44] startTask(): resuming timer task
[I][Controller.cpp:30] timerTask(): timer increase task
[I][Controller2.cpp:30] timerTask(): timer increase task2
[I][Controller.cpp:30] timerTask(): timer increase task
[I][Controller2.cpp:30] timerTask(): timer increase task2
[I][Controller.cpp:30] timerTask(): timer increase task

*/