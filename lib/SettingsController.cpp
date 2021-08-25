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

#include "SettingsController.h"

SettingsController::SettingsController(Settings settings, SettingsView settingsView){
    this->settings=settings;
    this->settingsView=settingsView;
}

void SettingsController::updateView(){
    this->settings.checkServerStatus();
    this->settingsView.showView(this->settings);
}
