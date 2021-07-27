#ifndef SETTINGSVIEW_H
#define SETTINGSVIEW_H

#include "Arduino.h"
#include <M5Stack.h>

#include "MenuItem.h"

class SettingsView : public MenuItem {
    /*private:
        int id;
        String title;*/

    public:
        SettingsView(){};
        SettingsView(int id, String title);
        int getId(){ return this->id; }
        String getTitle(){ return this->title; }

        void showView();
};


#endif