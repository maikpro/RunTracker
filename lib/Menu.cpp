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

#include "Menu.h"

Menu::Menu(){
    //Hier werdem die Menupunkte erstellt
    /*IMenuItem run(0, "Laufen");
    IMenuItem weather(1, "Wetter");
    IMenuItem timer(2, "Timer");
    IMenuItem settings(3, "Einstellungen");*/

    RunView run(0, "Laufen");
    WeatherView weather(1, "Weather");
    ClockView clock(2, "Clock");
    SettingsView settings(3, "Settings");
    
    
    this->menuList.push_back(run);
    this->menuList.push_back(weather);
    this->menuList.push_back(clock);
    this->menuList.push_back(settings);
    this->currentId=0;
    this->isMenuVisible=true;
}