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





