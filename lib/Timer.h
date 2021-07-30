#ifndef TIMER_H
#define TIMER_H

#include "Arduino.h"

class Timer {
    private:
        uint8_t hours;
        uint8_t minutes;
        uint8_t seconds;
        uint32_t execTime;
        bool start;
        bool stop;
        
    public:
        //Constructor
        Timer();

        //setter
        void setTimer(uint8_t hours, uint8_t minutes, uint8_t seconds);
        void setHours(uint8_t hours){ this->hours=hours; }
        void setMinutes(uint8_t minutes){ this->minutes=minutes; }
        void setSeconds(uint8_t seconds){ this->seconds=seconds; }
        void setExecTime(uint32_t execTime){ this->execTime=execTime; }

        void setStart(bool start){ this->start=start; }
        void setStop(bool stop){ this->stop=stop; }


        //getter
        uint8_t getHours(){ return this->hours; }
        uint8_t getMinutes(){ return this->minutes; }
        uint8_t getSeconds(){ return this->seconds; }
        uint32_t getExecTime(){ return this->execTime; }

        bool getStart(){ return this->start; }
        bool getStop(){ return this->stop; }


        //weitere Methoden
        void updateTime();
        void reset();
};

#endif