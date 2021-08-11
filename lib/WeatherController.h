#ifndef WEATHERCONTROLLER_H
#define WEATHERCONTROLLER_H

#include "Arduino.h"
#include <HTTPClient.h>

#include "Weather.h" //Modell
#include "WeatherView.h" //View

class WeatherController {
    private:
        Weather weatherModel;
        WeatherView weatherView;
        HTTPClient httpClient;
        bool isHeute;
        bool isWoche;

        //Local => http://192.168.178.37
        String restUrl = "http://192.168.178.37";
    
    public:
        WeatherController(Weather weatherModel, WeatherView weatherView);
        void updateView();
        /*zeigt heutiges Wetter an*/
        void heute();
        /*zeigt Wetter der ganzen Woche an*/
        void woche();

        void httpGetHeute();
        void httpGetWoche();
};

#endif