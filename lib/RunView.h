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

#ifndef RUNVIEW_H
#define RUNVIEW_H

#include "Arduino.h"
#include <M5Stack.h>

#include "MenuItem.h"
#include "Timer.h"
#include "GPS.h"

class RunView : public MenuItem {
    /*private:
        int id;
        String title;*/

    public:
        RunView(){};
        RunView(int id, String title);
        int getId(){ return this->id; }
        String getTitle(){ return this->title; }

        void showView(Timer timer, GPS gps);
};


#endif