#ifndef SLIDER_H
#define SLIDER_H

class SLIDER
{
    private:
        unsigned int PIN_PUL, PIN_DIR, PIN_ENA; // pin of TB-6560 step motor driver
        int POSITIVE_DIR;   // +1 or -1   positive direction is determined from config of motor and thread
        int STEP_PER_REV;   // number of step per revolution of motor
        int THREAD_LEAD;    // lead of thread screw in mm
        float DTC_PER_STEP; // distance per step

    public:
        SLIDER(unsigned int pinPul, unsigned int pinDir, unsigned int pinEna,
            int positiveDir, int stepPerRev,
            int threadLead);

        SLIDER();

        void move(int direction, int lapp);

};

#endif // SLIDER_H
