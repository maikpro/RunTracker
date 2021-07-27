#ifndef MENUITEM_H
#define MENUITEM_H

#include "Arduino.h"
#include <M5Stack.h>

class MenuItem {
    protected:
        int id;
        String title;
        
    public:
        MenuItem(){};
        
        int getId();
        String getTitle();

        void showView();
};

#endif