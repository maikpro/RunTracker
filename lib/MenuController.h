#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include "Arduino.h"
#include <M5Stack.h>

#include "Menu.h"
#include "MenuView.h"

class MenuController {
    private:
        Menu menuModel;
        MenuView menuView;

    public:
        MenuController(Menu menuModel, MenuView menuView);
        void updateView();
        void naechsterMenupunkt();
        void vorherigerMenupunkt();
        void setIsMenuVisible();
};

#endif