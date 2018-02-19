#include <Arduino.h>
#include <SLIDER.h>

//== constructor
SLIDER::SLIDER(unsigned int pinPul, unsigned int pinDir, unsigned int pinEna,
    int positiveDir, int stepPerRev,
    int threadLead){

    //== transfer
    PIN_PUL = pinPul;
    PIN_DIR = pinDir;
    PIN_ENA = pinEna;
    POSITIVE_DIR = positiveDir;
    STEP_PER_REV = stepPerRev;
    THREAD_LEAD = threadLead;
    // I didn't do anything with positiveDir yet

    DTC_PER_STEP = float(threadLead) / float(stepPerRev);  // in millimeter
    Serial.print("DTC_PER_STEP in mm = ");
    Serial.println(DTC_PER_STEP);
    /*
    @caution  Conversion to float must be done properly.
    I want DTC_PER_STEP to be integer data type, should I?
    However, I don't know all type of stepping.
    Full and half stepping correspond to 200 and 400 STEP_PER_REV.
    It seems that TB6560 allow 800 and 1600 STEP_PER_REV, but I didn't check them yet.
    */


    //== set pinMode and initialize
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


void SLIDER::move(float distance){
/*
distance is measured in millimeter

@improve    Combine direction into signed distance

@improve    delayMicroSec
delayMicroSec is somehow related to width of pulse.
I should properly study it and find the optimized value.
*/
    int delayMicroSec = 1000;
    long numStep;

    if ( distance * POSITIVE_DIR >= 0){
        digitalWrite(PIN_DIR, HIGH);
    } else {
        digitalWrite(PIN_DIR, LOW);
    }

    numStep = long( abs(distance)/DTC_PER_STEP );
    Serial.print("numStep = ");
    Serial.print( abs(distance)/DTC_PER_STEP);
    Serial.print("  ");
    Serial.println(numStep);
    /* @caution, @improve
    It is possible that numStep is not integer.
    I did NOT implement mechanism to verify that input distance match DTC_PER_STEP yet.
    */

    for(int a=0; a<numStep; a++){
        digitalWrite(PIN_PUL, HIGH);
        delayMicroseconds(delayMicroSec);
        digitalWrite(PIN_PUL, LOW);
        delayMicroseconds(delayMicroSec);
    }
}
