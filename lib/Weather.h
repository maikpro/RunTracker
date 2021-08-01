#ifndef WEATHER_H
#define WEATHER_H

#include "Arduino.h"

#include <ArduinoJson.h> //Um JSON Objekte zu parsen


class Weather{
    private:
        float temperatur;
        String datum;
        String wochentag;
        String data; //Daten aus der OpenWeatherApi
        
    public:
        Weather(){};
        Weather(float temperatur, String datum, String wochentag);
        
        void setTemperatur(float temperatur){ this->temperatur=temperatur; }
        void setDatum(String datum){ this->datum=datum; }
        void setWochentag(String wochentag){ this->wochentag=wochentag; }
        void setData(String data){ this->data=data; }
        
        float getTemperatur(){ return this->temperatur; }
        String getDatum(){ return this->datum; }
        String getWochentag(){ return this->wochentag; }
        String getData(){ return this->data; }

        //parse String into JSON
        void parseJSON();
        
};

#endif