
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

#include "Gps.h"

//Constructor member initializer list -> ein anderes Objekt initialisieren innerhalb der Klasse
GPS::GPS(): GPSRaw{ 2 }{
  this->GPSRaw.begin(9600);
};

bool GPS::getIsTracking(){
  return this->isTracking;
}

void GPS::setIsTracking(bool isTracking){
  this->isTracking = isTracking;
}

void GPS::readGPS(){
  //Quelle: https://m5stack.hackster.io/ptschulik/simple-gps-tracker-d3500e
  while (GPSRaw.available() > 0){/* Check if new GP data is available */
    this->tinyGPSPlus.encode(GPSRaw.read()); /* Read until no more data is available */
  }
}

void GPS::updateSatAnz(){
  this->satAnz = this->tinyGPSPlus.satellites.value();
}

/*Anzahl der Satelliten*/
uint32_t GPS::getSatAnz(){
  return this->satAnz;
}

void GPS::updateHDOP(){
  this->hdop = this->tinyGPSPlus.hdop.value();
};

/*zeigt den HDOP-Wert auf dem Display an.
HDOP: Horizontal Dilution Of Precision
für die Positionsbestimmung -> die Entfernungen zu mehreren Satelliten durch Signallaufzeitmessung */
int32_t GPS::getHDOP(){
  //HDOP = Bei Satellitennavigationssystemen ein Maß für die Streubreite der Messwerte. Da DOP von der relativen Position der Satelliten zueinander
  // H = Horizontal
  return this->hdop;
}

void GPS::updateCoords(){
  if( this->tinyGPSPlus.location.isValid() ){
    //latitude = Breitengrad
    //uint16_t lat = this->tinyGPSPlus.location.rawLat().deg;
    //this->lat = this->tinyGPSPlus.location.lat();
    //longitude = Längengrad
    //this->lng = this->tinyGPSPlus.location.lng();
    this->gpsPostion.setLat(this->tinyGPSPlus.location.lat());
    this->gpsPostion.setLng(this->tinyGPSPlus.location.lng());

  } else{
    //Dummy Coords
    this->gpsPostion.setLat(-99);
    this->gpsPostion.setLng(-99);
  }
}

void GPS::updateTime(){
  this->time.h = this->tinyGPSPlus.time.hour();
  this->time.min = this->tinyGPSPlus.time.minute();
  this->time.sec = this->tinyGPSPlus.time.second();
}

/*zeigt die aktuelle Uhrzeit an.*/
struct GPS::MyTime GPS::getTime(){
  //Uhrzeit
  return this->time;
  //M5.Lcd.printf("%02d:%02d:%02d", h+2, min, sec);
}

void GPS::updateDate(){
  //Datum
  this->date.tag = this->tinyGPSPlus.date.day();
  this->date.monat = this->tinyGPSPlus.date.month();
  this->date.jahr = this->tinyGPSPlus.date.year();
}

/*zeigt das aktuelle Datum an.*/
struct GPS::MyDate GPS::getDate(){
  //M5.Lcd.printf("%02d.%02d.%02d ", tag, monat, jahr);
  return this->date;
}

/*aktualisiert alle Werte vom GPS (SatAnz, HDOP, Koordinaten, Zeit, Datum)*/
void GPS::updateAll(){
  readGPS();
  updateSatAnz();
  updateHDOP();
  updateCoords();
  updateTime();
  updateDate();
}

void GPS::distanceBerechnen(){
  this->distance = this->tinyGPSPlus.distanceBetween(this->startPosition.getLat(), this->startPosition.getLng(), this->endPosition.getLat(), this->endPosition.getLng());
}