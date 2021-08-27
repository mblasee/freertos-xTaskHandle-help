#include <Arduino.h>
#include "Controller/Controller.h"
#include "Controller/Controller2.h"

void setup()
{
  vTaskSuspendAll();
  //this will create the Controller object. As for this example I put everything to the constructor this will be enough.
  Controller::getInstance();
  xTaskResumeAll();
  Controller::getInstance()->startTask();
}
const long interval = 5000;
static long currentMillis = 0;
bool stop = true;

const long interval1 = 10000;
static long currentMillis1 = 0;
bool stop1 = true;

void loop()
{
  //I know nothing is supposed to be here..its just here to show the idea quickly
  if (millis() - currentMillis >= interval && stop)
  {
    ESP_LOGI(TAG, "suspending");
    Controller::getInstance()->stopTask();
    Controller2::getInstance()->startTask();
    stop = false;
  }

  if (millis() - currentMillis1 >= interval1 && stop1)
  {
    ESP_LOGI(TAG, "resuming");
    Controller::getInstance()->startTask();
    stop1 = false;
  }
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