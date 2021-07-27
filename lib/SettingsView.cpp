#include "SettingsView.h"

SettingsView::SettingsView(int id, String title){
    this->id=id;
    this->title=title;
}

void SettingsView::showView(){
    M5.Lcd.setCursor(180, 110);
    M5.Lcd.println("New Settings");
}