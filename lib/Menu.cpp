#include "Menu.h"

Menu::Menu(){
    //Hier werdem die Menupunkte erstellt
    /*IMenuItem run(0, "Laufen");
    IMenuItem weather(1, "Wetter");
    IMenuItem timer(2, "Timer");
    IMenuItem settings(3, "Einstellungen");*/

    RunView run(0, "Laufen");
    RunView weather(1, "Laufen");
    RunView timer(2, "Laufen");
    RunView settings(3, "Laufen");
    
    
    this->menuList.push_back(run);
    this->menuList.push_back(weather);
    this->menuList.push_back(timer);
    this->menuList.push_back(settings);
    this->currentId=0;
    this->isMenuVisible=true;
}