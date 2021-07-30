#include "RunView.h"

RunView::RunView(int id, String title){
    this->id=id;
    this->title=title;
}

void RunView::showView(Timer timer){
    M5.Lcd.clearDisplay();
    M5.Lcd.setTextSize(6);
    M5.Lcd.setCursor(80, 110);
    M5.Lcd.printf("%02d:%02d", timer.getMinutes(), timer.getSeconds());
}