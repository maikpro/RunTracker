#include "ClockView.h"

ClockView::ClockView(int id, String title){
    this->id=id;
    this->title=title;
}

void ClockView::showView(Timer myClock){
    M5.Lcd.clearDisplay(WHITE);
    M5.Lcd.setTextColor(BLACK);
    M5.Lcd.setTextSize(4);
    M5.Lcd.setCursor(100, 120);
    M5.Lcd.printf("%02d:%02d:%02d", myClock.getHours(), myClock.getMinutes(), myClock.getSeconds() );

    //Steuerung
    M5.Lcd.setTextSize(1);
    M5.Lcd.setCursor(120, 220);
    M5.Lcd.println("Zurück");
}