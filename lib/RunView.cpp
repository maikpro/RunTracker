#include "RunView.h"

RunView::RunView(int id, String title){
    this->id=id;
    this->title=title;
}

void RunView::showView(Timer timer, GPS gps){
    M5.Lcd.clearDisplay(WHITE);
    M5.Lcd.setTextColor(BLACK);
    M5.Lcd.setTextSize(6);
    //Timerdaten
    M5.Lcd.setCursor(80, 110);
    M5.Lcd.printf("%02d:%02d", timer.getMinutes(), timer.getSeconds());

    //GPSdaten
    M5.Lcd.setTextSize(1);
    M5.Lcd.setCursor(0, 170);
    M5.Lcd.printf("Lat: %.6f\nLng: %.6f\nAnzSat: %d\nHDOP:%d\nDatum: %02d.%02d.%02d", gps.getLat(), gps.getLng(), gps.getSatAnz(), gps.getHDOP(), gps.getDate().tag, gps.getDate().monat, gps.getDate().jahr);

    //Steuerung
    M5.Lcd.setTextSize(1);
    M5.Lcd.setCursor(30, 220);
    M5.Lcd.println("Start/Pause");
    M5.Lcd.setCursor(140, 220);
    M5.Lcd.println("Zurück");
    M5.Lcd.setCursor(240, 220);
    M5.Lcd.println("Stop");
}