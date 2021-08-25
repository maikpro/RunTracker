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

#ifndef WEATHERCONTROLLER_H
#define WEATHERCONTROLLER_H

#include "Arduino.h"
#include <HTTPClient.h>
#include <ArduinoJson.h> //Um JSON Objekte zu parsen

#include "Weather.h" //Modell
#include "WeatherView.h" //View

#include <vector>
using namespace std;

class WeatherController {
    private:
        vector<Weather> weatherWoche;
        //Daten aus der OpenWeatherApi
        String data;
        Weather weatherModel;
        WeatherView weatherView;
        HTTPClient httpClient;
        bool isHeute;
        bool isWoche;

        String restUrl;
        //Local => http://192.168.178.37:3000
        //String restUrl = "http://192.168.178.37:3000";
    
    public:
        WeatherController(String restUrl, Weather weatherModel, WeatherView weatherView);
        void updateView();
        /*zeigt heutiges Wetter an*/
        void heute();
        /*zeigt Wetter der ganzen Woche an*/
        void woche();

        void httpGetHeute();
        void httpGetWoche();

        //parse String into JSON
        void parseJSONHeute();
        void parseJSONWoche();
};

#endif