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

#include "Arduino.h"
#include "Settings.h"

Settings::Settings(const char* ssid, const char* password, String restUrl){
  this->ssid=ssid;
  this->password=password;
  this->restUrl=restUrl;
}

void Settings::checkServerStatus(){
    HTTPClient httpClient;
    httpClient.begin(this->restUrl + "/settings");
    int status = httpClient.GET();

    if( status == 200 ){
        setServerStatus("online");
    } else {
        setServerStatus("offline");
    }
}