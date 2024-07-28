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

#ifndef MENUITEM_H
#define MENUITEM_H

#include "Arduino.h"
#include <M5Stack.h>

class MenuItem {
    protected:
        int id;
        String title;
        
    public:
        MenuItem(){};
        
        int getId();
        String getTitle();

        void showView();
};

#endif