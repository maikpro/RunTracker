#ifndef CLOCKCONTROLLER_H
#define CLOCKCONTROLLER_H

#include "Arduino.h"
#include <HTTPClient.h>

#include "Timer.h" //Modell
#include "ClockView.h" //View

class ClockController {
    private:
        Timer myClock;
        ClockView clockView;
        HTTPClient httpClient;
    
    public:
        ClockController(Timer myClock, ClockView clockView);
        void updateView();
        /*synchronisiert Clock einmal mit der Zeit aus einer Zeit-API*/
        void synchronization();
        void updateTime();
};

#endif