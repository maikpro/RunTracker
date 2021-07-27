#ifndef WEATHERVIEW_H
#define WEATHERVIEW_H

#include "Arduino.h"
#include <M5Stack.h>

#include "MenuItem.h"

class WeatherView : public MenuItem {
    /*private:
        int id;
        String title;*/

    public:
        WeatherView(){};
        WeatherView(int id, String title);
        int getId(){ return this->id; }
        String getTitle(){ return this->title; }

        void showView();
};


#endif