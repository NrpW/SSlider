#include <Arduino.h>
#include <SLIDER.h>

//== constructor
SLIDER::SLIDER(unsigned int pinPul, unsigned int pinDir, unsigned int pinEna,
    int positiveDir){

    PIN_PUL = pinPul;
    PIN_DIR = pinDir;
    PIN_ENA = pinEna;
    POSITIVE_DIR = positiveDir;
    // I didn't do anything with positiveDir yet

    // set pinMode and initialize
    pinMode(PIN_PUL, OUTPUT);
    pinMode(PIN_DIR, OUTPUT);
    pinMode(PIN_ENA, OUTPUT);

    digitalWrite(PIN_PUL, LOW);
    digitalWrite(PIN_DIR, HIGH);
    digitalWrite(PIN_ENA, LOW);
}


// null constructor
SLIDER::SLIDER(){
}


void SLIDER::move(int direction, int lapp){
    // lapp is going to be replaced by distance
    // This delay time is somehow related to width of pulse.
    int delayMicroSec = 1000;

    if ( direction >= 0){
        digitalWrite(PIN_DIR, HIGH);
    } else {
        digitalWrite(PIN_DIR, LOW);
    }

    for(int a=0; a<lapp; a++){
        digitalWrite(PIN_PUL, HIGH);
        delayMicroseconds(delayMicroSec);
        digitalWrite(PIN_PUL, LOW);
        delayMicroseconds(delayMicroSec);
    }
}
