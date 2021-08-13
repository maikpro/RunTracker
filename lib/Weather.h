#ifndef _WEATHER_H
#define _WEATHER_H

#include <ArduinoJson.h> //Um JSON Objekte zu parsen

#include <vector>
using namespace std;

class Weather {
  private:
    float temperatur;

    String datum;

    String wochentag;

    //Daten aus der OpenWeatherApi
    String data;

    //Sonnig, Bewölkt, Regen, ...
    String desc;

    String city;

    vector<String> wocheTemperaturen;

    vector<String> wocheDatum;

    vector<String> wocheDescription;


  public:
    Weather() {};

    Weather(float temperatur, String datum, String wochentag);

    void setTemperatur(float temperatur) { this->temperatur=temperatur; };

    void setDatum(String datum) { this->datum=datum; };

    void setWochentag(String wochentag) { this->wochentag=wochentag; };

    void setData(String data) { this->data=data; };

    void setDesc(String desc) { this->desc=desc; };

    void setCity(String city) { this->city=city; };

    float getTemperatur() { return this->temperatur; };

    String getDatum() { return this->datum; };

    String getWochentag() { return this->wochentag; };

    String getData() { return this->data; };

    String getDesc() { return this->desc; };

    String getCity() { return this->city; };

    vector<String> getWocheTemperaturen() { return this->wocheTemperaturen; };

    vector<String> getWocheDatum() { return this->wocheDatum; };

    vector<String> getWocheDescription() { return this->wocheDescription; };

    //parse String into JSON
    void parseJSONHeute();

    void parseJSONWoche();

    //leere die Arrays mit den Wochendaten!
    void clearArrays();

};
#endif
