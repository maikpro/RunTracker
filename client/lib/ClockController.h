/**
 * Hochschule Osnabrück - Modul: Internet of Things / Industrie 4.0
 * Projekt: RunTracker
 * Tech-Stack: M5Stack (C/C++), MQTT Broker (HIVEMQ), NodeJS (Server), MongoDB
 *
 * @author Maik Proba
 * Contact: maik.proba@hs-osnabrueck.de
 * 
 *  
 */

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
        String restUrl; 
    
    public:
        ClockController(String restUrl, Timer myClock, ClockView clockView);
        void updateView();
        /*synchronisiert Clock einmal mit der Zeit aus einer Zeit-API*/
        void synchronization();
        void updateTime();
};

#endif