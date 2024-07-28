/**
 * Hochschule Osnabrück - Modul: Internet of Things / Industrie 4.0
 * Projekt: RunTracker
 * Tech-Stack: M5Stack (C/C++), MQTT Broker (HIVEMQ), NodeJS (Server), MongoDB
 *
 * @author Maik Proba
 * Contact: maik.proba@hs-osnabrueck.de
 * 
 *  
 */

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