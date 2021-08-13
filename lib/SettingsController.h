#ifndef SETTINGSCONTROLLER_H
#define SETTINGSCONTROLLER_H

#include "Arduino.h"

#include "SettingsView.h"

class SettingsController {
    private:
        //kein Modell da Settings ausgelassen wird...
        SettingsView settingsView; 
    
    public:
        SettingsController(SettingsView settingsView);

        void updateView();
};

#endif