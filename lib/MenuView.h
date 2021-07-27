#ifndef MENUVIEW_H
#define MENUVIEW_H

#include "Arduino.h"
#include <M5Stack.h>

#include "MenuIcons.h"
#include "MenuItem.h"
#include "RunView.h"

class MenuView {
    public:
        void showMenu(int currentId);
        void changeView(int currentId, MenuItem menuItem);
        void showRun();
};

#endif