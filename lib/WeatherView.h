#ifndef WEATHERVIEW_H
#define WEATHERVIEW_H

#include "Arduino.h"
#include <M5Stack.h>

#include "MenuItem.h"
#include "Weather.h"

class WeatherView : public MenuItem{
    public:
        WeatherView(){};
        WeatherView(int id, String title);
        int getId(){ return this->id; }
        String getTitle(){ return this->title; }

        void showViewHeute(Weather weather);
        void showViewWoche(Weather weather);
};


#endif