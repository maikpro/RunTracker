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

#ifndef CLOCKVIEW_H
#define CLOCKVIEW_H

#include "Arduino.h"
#include <M5Stack.h>

#include "MenuItem.h"
#include "Timer.h"

class ClockView : public MenuItem {
    public:
        ClockView(){};
        ClockView(int id, String title);
        int getId(){ return this->id; }
        String getTitle(){ return this->title; }

        void showView(Timer myClock);
};


#endif