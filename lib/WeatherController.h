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
    
    public:
        WeatherController(Weather weatherModel, WeatherView weatherView);
        void updateView();
        /*zeigt heutiges Wetter an*/
        void heute();
        /*zeigt Wetter der ganzen Woche an*/
        void woche();

        void httpGet();
};

#endif