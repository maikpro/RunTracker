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

#ifndef GPS_H
#define GPS_H

#include "Arduino.h"
#include <TinyGPS++.h>
#include "Position.h"

class GPS {
    private:
        TinyGPSPlus tinyGPSPlus;
        HardwareSerial GPSRaw; /* By default, GPS is connected with M5Core through UART2 */
        uint32_t satAnz;
        int32_t hdop;
        
        Position gpsPostion;
        Position startPosition;
        Position endPosition;
        double distance;

        bool isTracking=false;
        bool isStartPosSet=false;

        struct MyTime{
            uint8_t h;
            uint8_t min;
            uint8_t sec;
        } time;

        struct MyDate{
            uint8_t tag;
            uint8_t monat;
            uint16_t jahr;
        } date;

        
    public:
        //Constructor
        GPS();

        //display
        uint32_t getSatAnz();
        int32_t getHDOP();
        //double getLat();
        //double getLng();

        Position getGPSPosition(){ return this->gpsPostion; }
        Position getStartPosition(){ return this->startPosition; }
        Position getEndPosition(){ return this->endPosition; }
        double getDistance(){ return this->distance; }

        void updateStartPosition(){
            this->startPosition.setLat(this->tinyGPSPlus.location.lat());
            this->startPosition.setLng(this->tinyGPSPlus.location.lng());
        }

        void updateEndPostion(){
            this->endPosition.setLat(this->tinyGPSPlus.location.lat());
            this->endPosition.setLng(this->tinyGPSPlus.location.lng());
        }

        struct MyTime getTime();
        struct MyDate getDate();

        bool getIsTracking();
        bool getIsStartPosSet(){ return this->isStartPosSet; };

        //werte aktualisieren
        void readGPS();
        void updateSatAnz();
        void updateHDOP();
        void updateCoords();
        void updateTime();
        void updateDate();
        void updateAll();

        void distanceBerechnen();

        void setIsTracking(bool isTracking);
        void setIsStartPosSet(bool isStartPosSet ){ this->isStartPosSet = isStartPosSet; }

        //Distanz berechnen
        void setPosition();
};

#endif