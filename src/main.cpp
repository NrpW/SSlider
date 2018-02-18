#include <Arduino.h>

#include "parameter.h"

parameter prmt;

void setup() {
    Serial.begin(prmt.BaudRate);
    Serial.setTimeout(5000);

    pinMode(prmt.StppPinPul, OUTPUT);
    pinMode(prmt.StppPinDir, OUTPUT);
    pinMode(prmt.StppPinEna, OUTPUT);

    //== initialize
    digitalWrite(prmt.StppPinPul, HIGH);
    digitalWrite(prmt.StppPinDir, LOW);
    digitalWrite(prmt.StppPinEna, LOW);
}

int delayMicroSec = 1000;
void lap(int lapp){
    for(int a=0; a<lapp; a++){
        digitalWrite(prmt.StppPinPul, HIGH);
        delayMicroseconds(delayMicroSec);
        digitalWrite(prmt.StppPinPul, LOW);
        delayMicroseconds(delayMicroSec);
    }
}

void loop() {
    digitalWrite(prmt.StppPinDir, HIGH);
    lap(1600);
    delay(2000);
    digitalWrite(prmt.StppPinDir, LOW);
    lap(1600);
    delay(2000);

}
