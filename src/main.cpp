#include <Arduino.h>

#include "parameter.h"
#include "SLIDER.h"

parameter prmt;
SLIDER xSlider(10, 8, 9, +1);
//@improve  I want to initialize this class with data from prmt.

void setup() {
    Serial.begin(prmt.BaudRate);
    Serial.setTimeout(5000);

}

void loop() {
    xSlider.move(+1, 800);
    delay(2000);
    xSlider.move(-1, 800);
    delay(2000);

}
