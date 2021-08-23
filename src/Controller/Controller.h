#ifndef Controller_h
#define Controller_h
#include <Arduino.h>
#include "TaskHandles/TaskHandles.h"

class Controller
{
public:
    static Controller *getInstance();
    Controller();
    static void startTimerTask(void *params);
    static void startTimerStopTask(void *params);

private:
    static Controller *instance;
    void timerTask();
    void timerStopTask();
};

#endif