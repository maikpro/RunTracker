#ifndef CLOCKVIEW_H
#define CLOCKVIEW_H

#include "Arduino.h"
#include <M5Stack.h>

#include "MenuItem.h"
#include "Timer.h"

class ClockView : public MenuItem {
    public:
        ClockView(){};
        ClockView(int id, String title);
        int getId(){ return this->id; }
        String getTitle(){ return this->title; }

        void showView(Timer myClock);
};


#endif