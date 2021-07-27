#ifndef CLOCKVIEW_H
#define CLOCKVIEW_H

#include "Arduino.h"
#include <M5Stack.h>

#include "MenuItem.h"

class ClockView : public MenuItem {
    /*private:
        int id;
        String title;*/

    public:
        ClockView(){};
        ClockView(int id, String title);
        int getId(){ return this->id; }
        String getTitle(){ return this->title; }

        void showView();
};


#endif