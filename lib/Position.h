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

#ifndef POSITION_H
#define POSITION_H

#include "Arduino.h"

class Position {
    private:
        double lat;
        double lng;
       
    public:
        Position(){}
        Position(double lat, double lng){
            this->lat=lat;
            this->lng=lng;
        }

        double getLat(){ return this->lat; }
        double getLng(){ return this->lng; }

        void setLat(double lat){ this->lat=lat; }
        void setLng(double lng){ this->lng=lng; }
};

#endif