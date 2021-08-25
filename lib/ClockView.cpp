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

#include "ClockView.h"

ClockView::ClockView(int id, String title){
    this->id=id;
    this->title=title;
}

void ClockView::showView(Timer myClock){
    M5.Lcd.clearDisplay(WHITE);
    M5.Lcd.setTextColor(BLACK);
    
    //Datum
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(200, 20);
    M5.Lcd.println(myClock.getDate());

    //Zeit
    M5.Lcd.setTextSize(6);
    M5.Lcd.setCursor(20, 110);
    M5.Lcd.printf("%02d:%02d:%02d", myClock.getHours(), myClock.getMinutes(), myClock.getSeconds() );

    //Steuerung
    M5.Lcd.setTextSize(1);
    M5.Lcd.setCursor(140, 220);
    M5.Lcd.println("Zurück");
}