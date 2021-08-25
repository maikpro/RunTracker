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

#ifndef SETTINGSCONTROLLER_H
#define SETTINGSCONTROLLER_H

#include "Arduino.h"

#include "Settings.h"
#include "SettingsView.h"

class SettingsController {
    private:
        Settings settings;
        SettingsView settingsView; 
    
    public:
        SettingsController(Settings settings, SettingsView settingsView);

        void updateView();
};

#endif