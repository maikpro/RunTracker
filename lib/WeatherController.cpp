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

#include "WeatherController.h"

WeatherController::WeatherController(String restUrl, Weather weatherModel, WeatherView weatherView){
    this->restUrl=restUrl;
    this->weatherModel=weatherModel;
    this->weatherView=weatherView;

    this->isHeute=true;
    this->isWoche=false;
}

void WeatherController::updateView(){
    if( this->isHeute ){
        httpGetHeute();
        this->weatherView.showViewHeute(this->weatherModel);
    } else if( this->isWoche ){
        httpGetWoche();
        this->weatherView.showViewWoche(this->weatherModel, this->weatherWoche);
    }
}

void WeatherController::heute(){
    //heutiges Wetter anzeigen...
    this->isHeute=true;
    this->isWoche=false;
}

void WeatherController::woche(){
    //wetter der ganzen Woche anzeigen...
    this->isWoche=true;
    this->isHeute=false;
}

//parse String into JSON
void WeatherController::parseJSONHeute() {
    const int capacity = JSON_OBJECT_SIZE(60); //ca. 60 JSON Objects
    StaticJsonDocument<capacity> doc;
    deserializeJson(doc, this->data);

    String temp = doc["temp"];
    String date = doc["date"];
    String wochentag = doc["wochentag"];
    //Beschreibung Bewölkt, Regen, Sonne...
    String desc = doc["description"];
    String city = doc["city"];
    
    //String temperatur, String datum, String wochentag, String description, String city
    this->weatherModel=Weather(temp, date, wochentag, desc, city);
}

//"https://api.openweathermap.org/data/2.5/weather?q=osnabrueck&units=metric&appid=myKey"
void WeatherController::httpGetHeute(){
    //this->httpClient.begin("https://api.openweathermap.org/data/2.5/weather?q=osnabrueck&units=metric&appid=" + myApiKey);
    
    this->httpClient.begin(this->restUrl + "/weather/api/heute"); //REST API vom NodeJS Server
    int httpStatus = httpClient.GET();
    
    if(httpStatus == 200){
        String dataFromApi = httpClient.getString();
        this->data=dataFromApi;
        parseJSONHeute(); //Temperatur erstmal auslesen...
    }

    httpClient.end();
}

void WeatherController::parseJSONWoche() {

    this->weatherWoche.clear();
    const int capacity = JSON_OBJECT_SIZE(60); //ca. 60 JSON Objects
    StaticJsonDocument<capacity> doc;
    deserializeJson(doc, this->data);

    for(int i = 0; i < doc.size(); i++){
        String temp = doc[i]["temp"];
        String date = doc[i]["date"];
        String wochentag = doc[i]["weekday"];
        String description = doc[i]["description"];

        
        Weather newWeather(temp, date, wochentag, description);
        this->weatherWoche.push_back(newWeather);
    }
}

void WeatherController::httpGetWoche(){
    //Wochen API auslesen!!
    this->httpClient.begin(restUrl + "/weather/api/woche"); //REST API vom NodeJS Server
    int httpStatus = httpClient.GET();
    
    if(httpStatus == 200){
        String dataFromApi = httpClient.getString();
        this->data = dataFromApi;
        parseJSONWoche(); //Temperatur erstmal auslesen...
    }

    httpClient.end();
}