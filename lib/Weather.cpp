#include "Weather.h"

#include <M5Stack.h>

Weather::Weather(float temperatur, String datum, String wochentag){
    this->temperatur=temperatur;
    this->datum=datum;
    this->wochentag=wochentag;
}  

void Weather::parseJSONHeute(){
    const int capacity = JSON_OBJECT_SIZE(60); //ca. 60 JSON Objects
    StaticJsonDocument<capacity> doc;
    deserializeJson(doc, this->data);
    
    //Temperatur des Wetters
    float temp = doc["main"]["feels_like"];
    setTemperatur(temp);

    //Beschreibung Bewölkt, Regen, Sonne...
    String desc = doc["weather"][0]["main"];
    setDesc(desc);

    //Stadtname
    String city = doc["name"];
    setCity(city);
}

void Weather::clearArrays(){
    this->wocheTemperaturen.clear();
}

void Weather::parseJSONWoche(){
    clearArrays();
    const int capacity = JSON_OBJECT_SIZE(60); //ca. 60 JSON Objects
    StaticJsonDocument<capacity> doc;
    deserializeJson(doc, this->data);


    for(int i = 0; i < doc.size(); i++){
        String temp = doc[i]["temp"];
        this->wocheTemperaturen.push_back(temp);
        String date = doc[i]["date"];
        this->wocheDatum.push_back(date);
        String description = doc[i]["description"];
        this->wocheDescription.push_back(description);
    }
}