#include "parameter.h"

using namespace std;

parameter::parameter()
{
    /* @improve   this will be loaded from a file. */
    BaudRate = 115200;

    //====
    StppPinPul = 10;  // pin of Stepper PULSE
    StppPinDir = 8;   // Stepper Pin for Direction
    StppPinEna = 9;   // Stepper Pin for Enable

}
