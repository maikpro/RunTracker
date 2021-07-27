#include "RunView.h"

RunView::RunView(int id, String title){
    this->id=id;
    this->title=title;
}

void RunView::showView(){
    M5.Lcd.setCursor(150, 120);
    M5.Lcd.println("New Runner Test Test");
}