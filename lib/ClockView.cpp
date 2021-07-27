#include "ClockView.h"

ClockView::ClockView(int id, String title){
    this->id=id;
    this->title=title;
}

void ClockView::showView(){
    M5.Lcd.setCursor(140, 160);
    M5.Lcd.println("New Clock");
}