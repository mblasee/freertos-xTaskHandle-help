#ifndef TaskHandles_h
#define TaskHandles_h
#include <Arduino.h>

class TaskHandles
{
public:
    static TaskHandles *getInstance();
    TaskHandles();

    xTaskHandle getTimerHandle();
    xTaskHandle getTimerStopHandle();

private:
    static TaskHandles *instance;
    xTaskHandle *timerHandle = nullptr;
    xTaskHandle *timerStopHandle = nullptr;
};

#endif