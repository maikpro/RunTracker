#ifndef SETTINGSVIEW_H
#define SETTINGSVIEW_H

#include "Arduino.h"
#include <M5Stack.h>

#include "MenuItem.h"
#include "Settings.h" //Modell

class SettingsView : public MenuItem {
    
    public:
        SettingsView(){};
        SettingsView(int id, String title);
        int getId(){ return this->id; }
        String getTitle(){ return this->title; }

        void showView(Settings settings);
};


#endif