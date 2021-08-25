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

#include "SettingsView.h"

SettingsView::SettingsView(int id, String title){
    this->id=id;
    this->title=title;
}

void SettingsView::showView(Settings settings){
    M5.Lcd.clearDisplay(WHITE);
    M5.Lcd.setTextColor(BLACK);

    //Einstellungen
    //Verbindungsdaten
    M5.Lcd.setTextSize(1);
    //SSID
    M5.Lcd.setCursor(20, 20);
    M5.Lcd.printf("SSID: %s", settings.getSSID());

    //URL
    M5.Lcd.setCursor(20, 50);
    M5.Lcd.println( "URL: " + settings.getRestUrl() );

    //Internet-Verbindungsstatus
    M5.Lcd.setCursor(20, 80);
    String status = (settings.getWiFiStatus() == WL_CONNECTED) ? "Verbunden" : "Nicht verbunden";
    M5.Lcd.println( "Internetverbindung: " + status );

    //Serverstatus
    M5.Lcd.setCursor(20, 120);
    M5.Lcd.println( "Serverstatus: " + settings.getServerStatus() );

    //Batterie anzeige
    M5.Lcd.setCursor(20, 150);
    uint8_t ladestand = M5.Power.getBatteryLevel();
    M5.Lcd.printf("Batterie: %d", ladestand);


    //Steuerung
    M5.Lcd.setTextSize(1);
    M5.Lcd.setCursor(140, 220);
    M5.Lcd.println("Zurück");
}