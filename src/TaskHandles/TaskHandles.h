#ifndef TaskHandles_h
#define TaskHandles_h
#include <Arduino.h>

class TaskHandles
{
public:
    static TaskHandles *getInstance();
    TaskHandles();

    TaskHandle_t getTimerHandle();
    TaskHandle_t getTimerStopHandle();

private:
    static TaskHandles *instance;
    TaskHandle_t timerHandle = nullptr;
    TaskHandle_t timerStopHandle = nullptr;
};

#endif