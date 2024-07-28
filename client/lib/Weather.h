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

#ifndef WEATHER_H
#define WEATHER_H

#include "Arduino.h"

class Weather {
  private:
    String temperatur;
    String datum;
    String wochentag;
    //Sonnig, Bewölkt, Regen, ...
    String description;
    String city;


  public:
    Weather() {};
    Weather(String temperatur, String datum, String wochentag, String description, String city); //HEUTE MIT CITY
    Weather(String temperatur, String datum, String wochentag, String description); //WOCHE WEATHER OHNE CITY

    void setTemperatur(String temperatur) { this->temperatur=temperatur; };
    void setDatum(String datum) { this->datum=datum; };
    void setWochentag(String wochentag) { this->wochentag=wochentag; };
    void setDesc(String description) { this->description=description; };
    void setCity(String city) { this->city=city; };
    
    String getTemperatur() { return this->temperatur; };
    String getDatum() { return this->datum; };
    String getWochentag() { return this->wochentag; };
    String getDescription() { return this->description; };
    String getCity() { return this->city; };
};

#endif