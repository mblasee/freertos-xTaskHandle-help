#ifndef Controller_h
#define Controller_h
#include <Arduino.h>

class Controller
{
public:
    static Controller *getInstance();
    Controller();
    void startTask();
    void stopTask();

private:
    static Controller *instance;
    TaskHandle_t controllerTask;
    static void startTimerTask(void *params);
    void timerTask();
};

#endif