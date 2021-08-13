#ifndef GPS_H
#define GPS_H

#include "Arduino.h"
#include <TinyGPS++.h>

class GPS {
    private:
        TinyGPSPlus tinyGPSPlus;
        HardwareSerial GPSRaw; /* By default, GPS is connected with M5Core through UART2 */
        uint32_t satAnz;
        int32_t hdop;
        double lat; //latitude = Breitengrad
        double lng; //longitude = Längengrad

        bool isTracking=false;

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
        double getLat();
        double getLng();
        struct MyTime getTime();
        struct MyDate getDate();

        bool getIsTracking();

        //werte aktualisieren
        void readGPS();
        void updateSatAnz();
        void updateHDOP();
        void updateCoords();
        void updateTime();
        void updateDate();
        void updateAll();

        void setIsTracking(bool isTracking);


        //Distanz berechnen
        void setPosition();
};

#endif