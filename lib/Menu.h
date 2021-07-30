#ifndef MENU_H
#define MENU_H

#include "Arduino.h"
#include <M5Stack.h>
#include <vector>


#include "MenuItem.h"
#include "RunView.h"
#include "WeatherView.h"
#include "ClockView.h"
#include "SettingsView.h"

using namespace std;

class Menu {
    private:
        vector<MenuItem> menuList;
        int currentId;
        bool isMenuVisible;

    public:
        Menu();
        int getCurrentId(){ return this->currentId; };
        bool getIsMenuVisible(){ return this->isMenuVisible; };
        MenuItem getMenuItem(){ return this->menuList.at(this->currentId); };
        
        void setCurrentId(int currentId){ this->currentId = currentId; };
        void setIsMenuVisible(bool isMenuVisible){ this->isMenuVisible=isMenuVisible; };
};

#endif