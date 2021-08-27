#ifndef Controller2_h
#define Controller2_h
#include <Arduino.h>

class Controller2
{
public:
    static Controller2 *getInstance();
    Controller2();
    void startTask();
    void stopTask();

private:
    static Controller2 *instance;
    TaskHandle_t controllerTask;
    static void startTimerTask(void *params);
    void timerTask();
};

#endif