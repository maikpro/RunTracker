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

#ifndef WEATHERVIEW_H
#define WEATHERVIEW_H

#include "Arduino.h"
#include <M5Stack.h>

#include "MenuItem.h"
#include "Weather.h"

#include <vector>
using namespace std;

class WeatherView : public MenuItem{
    public:
        WeatherView(){};
        WeatherView(int id, String title);
        int getId(){ return this->id; }
        String getTitle(){ return this->title; }

        void showViewHeute(Weather weather);
        void showViewWoche(Weather weather, vector<Weather> weatherWoche);
};


#endif