#ifndef RUNCONTROLLER_H
#define RUNCONTROLLER_H

#include "Arduino.h"
#include <M5Stack.h>

#include "Timer.h" //Modell
#include "RunView.h" //View

class RunController {
    private:
        Timer timerModel;
        RunView runView;
        bool isRunVisible;

    public:
        RunController(Timer timerModel, RunView runView);
        void updateTime();
        void updateView();

        //Buttons
        void start();
        void pause();
        void stop();
        void buttonInteractions(uint8_t pinButtonA, uint8_t pinButtonB, uint8_t pinButtonC);
};

#endif