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
#include "Timer.h"

Timer::Timer(){
    reset();
}

/*aktualisiert die Anzeige der Timerzeit*/
void Timer::updateTime(){
  this->seconds++;
  if (this->seconds == 60) {
    this->seconds = 0;
    this->minutes++;
    
    if(this->minutes > 59) {
      this->minutes = 0;
      this->hours++;
      
      if (this->hours > 23) {
        this->hours = 0;
      }
    }
  }
}

void Timer::reset(){
  setHours(0);
  setMinutes(0);
  setSeconds(0);
  setStart(false);
  setStop(false);
  setExecTime(0);
}

void Timer::parseJSON(){
  const int capacity = JSON_OBJECT_SIZE(60); //ca. 60 JSON Objects
  StaticJsonDocument<capacity> doc;
  deserializeJson(doc, this->data);

  int hour = doc["hour"];
  int minutes = doc["minute"];
  int seconds = doc["seconds"];

  String date = doc["date"];

  setHours(hour);
  setMinutes(minutes);
  setSeconds(seconds);
  setDate(date);
}





