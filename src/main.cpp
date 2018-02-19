#include <Arduino.h>

#include "parameter.h"
#include "SLIDER.h"

parameter prmt;
SLIDER xSlider(10, 8, 9, -1, 200, 4);
//@improve  I want to initialize this class with data from prmt.
/* == current config
lead = 4mm;
stepPerRev = 200;  // full step setting
positiveDir = -1;  // from trial and error
*/

void setup() {
    Serial.begin(prmt.BaudRate);
    Serial.setTimeout(5000);

    delay(10000);
}

void loop() {
    xSlider.move(+1, 20);
    delay(2000);
    xSlider.move(-1, 20);
    delay(2000);

}
