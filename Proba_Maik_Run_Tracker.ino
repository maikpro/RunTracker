

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

#include "Menu.h" //Modell
#include "MenuView.h" //View
#include "MenuController.h" //Controller

#include "Timer.h" //Modell
#include "RunView.h" //View
#include "RunController.h" //Controller

Menu menu;
MenuView menuView;
MenuController menuController(menu, menuView);

Timer timer;
RunView runView;
RunController runController(timer, runView);


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



void setup() {
   //M5Stack Init
   M5.begin();
   M5.Power.begin();
}

void loop() {

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

      //Wenn Button B gedrückt wird:
      //attachInterrupt(buttonB, run_buttonB_clicked, RISING);

      //Wenn Button C (STOP) gedrückt wird:
      attachInterrupt(buttonC, run_buttonC_clicked, RISING);

      //3 Sekunden mittleren Button gedrückt halten um ins Hauptmenu zu gelangen. 
      if( M5.BtnB.pressedFor(3000) ){
         menuController.setIsMenuVisible();
      }

      delay(1000); //Flackern verhindern...
   }

   runController.updateTime(); //Timer soll auch weiterlaufen wenn der View gewechselt wird...
}

