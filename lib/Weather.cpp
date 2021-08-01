#include "Weather.h"

Weather::Weather(float temperatur, String datum, String wochentag){
    this->temperatur=temperatur;
    this->datum=datum;
    this->wochentag=wochentag;
}  

void Weather::parseJSON(){
    const int capacity = JSON_OBJECT_SIZE(40); //ca. 40 JSON Objects
    StaticJsonDocument<capacity> doc;
    deserializeJson(doc, this->data);
    float temp = doc["main"]["feels_like"];
    setTemperatur(temp);
}