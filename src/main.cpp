#include <Arduino.h>
#include "Controller/Controller.h"

void setup()
{
  //this will create the Controller object. As for this example I put everything to the constructor this will be enough.
  Controller::getInstance();
}

void loop()
{
  // put your main code here, to run repeatedly:
}