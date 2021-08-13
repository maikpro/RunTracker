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

#include <M5Stack.h>
#include <WiFi.h>

#include "Menu.h" //Modell
#include "MenuView.h" //View
#include "MenuController.h" //Controller

#include "Timer.h" //Modell
#include "GPS.h" //Modell 2
#include "RunView.h" //View
#include "RunController.h" //Controller

#include "Weather.h" //Modell
#include "WeatherView.h" //View
#include "WeatherController.h" //Controller

//Clock Modell ist GPS da es die Zeut hält ist kein weiteres Modell für Clock nötig!
#include "ClockView.h" //View
#include "ClockController.h" //Controller

#include "SettingsView.h"
#include "SettingsController.h"

#include <WiFiClient.h>
#include <PubSubClient.h>
#include "MyMQTTClient.h" //Wird genutzt um MQTT Nachrichten zu verschicken

//WLAN Zugang
const char* ssid = "NoFreeWiFi";
const char* password = "57655658286507878869";

//Server IP + Port:
String restUrl = "http://192.168.178.37:3000";

//Initialisierung des PubSubClients
WiFiClient wifiClient;
PubSubClient pubSubClient(wifiClient);
MyMQTTClient myMQTTClient(pubSubClient);

//Funktionen
//Hauptmenü
Menu menu;
MenuView menuView;
MenuController menuController(menu, menuView);

//Lauf-Funktion
Timer timer;
GPS gps;
RunView runView;
RunController runController(timer, gps, myMQTTClient, runView);

//Wetter-Funktion
Weather weather;
WeatherView weatherView;
WeatherController weatherController(restUrl, weather, weatherView);

//Uhrzeit-Funktion
Timer myClock; //Timer wird als Clock genutzt um doppelten Code zu vermeiden --> clock synchronisiert mit der Zeit von GPS und läuft dann unabhängig weiter!
ClockView clockView;
ClockController clockController(restUrl, myClock, clockView);

//Settings-Funktion
//kein Settings Modell
SettingsView settingsView;
SettingsController settingsController(settingsView);

//Die Pinbezeichnungen für die Buttons lauten GPIO_NUM_39 (BtnA), GPIO_NUM_38 (BtnB) sowie GPIO_NUM_37 (BtnC).
uint8_t buttonA = GPIO_NUM_39;
uint8_t buttonB = GPIO_NUM_38;
uint8_t buttonC = GPIO_NUM_37; 


void hauptmenu_buttonA_clicked(){
   menuController.vorherigerMenupunkt();
}

void hauptmenu_buttonB_clicked(){
   menuController.setIsMenuVisible();
}

void hauptmenu_buttonC_clicked(){
   menuController.naechsterMenupunkt();
}

void run_buttonA_clicked(){
   runController.start();
}

//run_buttonB_clicked... soll nicht belegt werden damit Nutzer zurück zum Hauptmenu kann...

void run_buttonC_clicked(){
   runController.stop();
}

void weather_buttonA_clicked(){
   weatherController.heute();
}

void weather_buttonC_clicked(){
   weatherController.woche();
}

void setup() {
   Serial.begin(115200);
    //1. Initialisierung der WiFi-Verbindung
   WiFi.begin(ssid, password);
   WiFi.setSleep(false);
   //2. Warten auf erfolgreiche WiFi-Verbindung 
   while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(1000);
   }
   M5.begin();
   M5.Power.begin();
}



void loop() {
   //3 Sekunden mittleren Button gedrückt halten um ins Hauptmenu zu gelangen. 
   if( menuController.getIsMenuVisible()==false && M5.BtnB.pressedFor(3000) ){
      menuController.setIsMenuVisible();
   }
   //Wenn Nutzer im Hauptmenu:
   if( menuController.getIsMenuVisible() ){
      //Menu aktualisieren
      menuController.updateView();
      //Nutzer wechselt Menupunkt
      //Wenn Button A gedrückt wird:
      attachInterrupt(buttonA, hauptmenu_buttonA_clicked, RISING);
      //Wenn Button B gedrückt wird:
      attachInterrupt(buttonB, hauptmenu_buttonB_clicked, RISING);
      //Wenn Button C (->) gedrückt wird:
      attachInterrupt(buttonC, hauptmenu_buttonC_clicked, RISING);
   }
   //Wenn Nutzer im RunView ist:
   else if( menuController.getIsMenuVisible()==false && menuController.getCurrentId() == 0 ){
      M5.Lcd.clearDisplay();
      runController.updateView();
      //Wenn Button A (START) gedrückt wird:
      attachInterrupt(buttonA, run_buttonA_clicked, RISING);
      //Wenn Button C (STOP) gedrückt wird:
      attachInterrupt(buttonC, run_buttonC_clicked, RISING);
      delay(500); //Flackern verhindern...
   }
   //Wenn Nutzer im WeatherView ist:
   else if( menuController.getIsMenuVisible()==false && menuController.getCurrentId() == 1 ){
      weatherController.updateView();
      //Button Interakionen
      //Wenn Button A (HEUTE) gedrückt wird:
      attachInterrupt(buttonA, weather_buttonA_clicked, RISING);
      //Wenn Button C (WOCHE) gedrückt wird:
      attachInterrupt(buttonC, weather_buttonC_clicked, RISING);
      delay(1000);
   }
   //Wenn Nutzer im ClockView ist:
   else if( menuController.getIsMenuVisible() == false && menuController.getCurrentId() == 2 ){
      clockController.updateView();
      delay(750);
   }

   else if( menuController.getIsMenuVisible() == false && menuController.getCurrentId() == 3 ){
      settingsController.updateView();
   }

   runController.updateTime(); //Timer soll auch weiterlaufen wenn der View gewechselt wird...
   M5.update();
}

