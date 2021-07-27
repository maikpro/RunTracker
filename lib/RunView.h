#ifndef RUNVIEW_H
#define RUNVIEW_H

#include "Arduino.h"
#include <M5Stack.h>

#include "MenuItem.h"

class RunView : public MenuItem {
    /*private:
        int id;
        String title;*/

    public:
        RunView(){};
        RunView(int id, String title);
        int getId(){ return this->id; }
        String getTitle(){ return this->title; }

        void showView();
};


#endif