#ifndef SLIDER_H
#define SLIDER_H

class SLIDER
{
    private:
        unsigned int PIN_PUL, PIN_DIR, PIN_ENA;
        int POSITIVE_DIR;

    public:
        SLIDER(unsigned int pinPul, unsigned int pinDir, unsigned int pinEna,
            int positiveDir);
        SLIDER();

        void move(int direction, int lapp);

};

#endif // SLIDER_H
