#include "WeatherView.h"

WeatherView::WeatherView(int id, String title){
    this->id=id;
    this->title=title;
}

void WeatherView::showView(){
    M5.Lcd.setCursor(120, 120);
    M5.Lcd.println("New Weather");
}