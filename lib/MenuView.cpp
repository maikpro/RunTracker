#include "MenuView.h"

void MenuView::showMenu(int currentId){
    //Menu Anzeigen
    switch(currentId) {
        case 0:
            M5.Lcd.drawBitmap(0, 0, 320, 240, (uint16_t *) runSelected_menuIcons);
            break;
        case 1:
            M5.Lcd.drawBitmap(0, 0, 320, 240, (uint16_t *) weatherSelected_menuIcons);
            break;
        case 2:
            M5.Lcd.drawBitmap(0, 0, 320, 240, (uint16_t *) timerSelected_menuIcons);
            break;
        case 3:
            M5.Lcd.drawBitmap(0, 0, 320, 240, (uint16_t *) settingsSelected_menuIcons);
            break;
        default:
            M5.Lcd.drawBitmap(0, 0, 320, 240, (uint16_t *) no_selection_menuIcons);
    }
}
/*
void MenuView::changeView(int currentId, MenuItem menuItem){
    M5.Lcd.clearDisplay();
    switch(currentId) {
        case 0:
            //showRun
            {
                //Downcast Parent(MenuItem) -> Child (RunView) 
                RunView* run = (RunView*) &menuItem;
                run->showView();
                break;
            }
        
        case 1:
            //showWeather
            {
                WeatherView* weather = (WeatherView*) &menuItem;
                weather->showView();
                break;
            }
        
        case 2:
            //showClock
            {
                ClockView* clock = (ClockView*) &menuItem;
                clock->showView();
                break;
            }

        case 3:
            //showSettings
            {
                SettingsView* settings = (SettingsView*) &menuItem;
                settings->showView();
                break;
            }
            
        default:
            //nothing
            break;
    }
}*/