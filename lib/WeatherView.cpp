#include "WeatherView.h"

WeatherView::WeatherView(int id, String title){
    this->id=id;
    this->title=title;
}

void WeatherView::showView(Weather weather){
    M5.Lcd.clearDisplay();
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(120, 120);
    M5.Lcd.println("New Weather");
}