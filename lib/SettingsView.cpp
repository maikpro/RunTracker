#include "SettingsView.h"

SettingsView::SettingsView(int id, String title){
    this->id=id;
    this->title=title;
}

void SettingsView::showView(){
    M5.Lcd.clearDisplay();
    M5.Lcd.setCursor(140, 110);
    M5.Lcd.println("Settings Funktion...");
}