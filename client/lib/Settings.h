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

#ifndef SETTINGS_H
#define SETTINGS_H

#include <WiFi.h>
#include "Arduino.h"

#include <HTTPClient.h>

class Settings {
    private:
        const char* ssid;
        const char* password;
        String restUrl;
        String serverStatus;

    public:
        Settings(){};
        Settings(const char* ssid, const char* password, String restUrl);
        const char* getSSID(){ return this->ssid; }
        String getRestUrl(){ return this->restUrl; }
        String getServerStatus(){ return this->serverStatus; }

        void setServerStatus(String serverStatus){ this->serverStatus = serverStatus; }

        static wl_status_t getWiFiStatus(){ return WiFi.status(); }
        void checkServerStatus();
        
};

#endif