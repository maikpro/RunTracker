

/**
 * Hochschule Osnabrück - Modul: Internet of Things / Industrie 4.0 (Praktikum)
 * Versuch 4: Überwachung der Bodenfeuchtigkeit
 * 
 * @file Proba_Maik_Versuch_4.ino
 *
 * @brief Ziel ist es, das Feuchtigkeitslevel der Erde in einem Blumentopf zu messen und dadurch entscheiden zu können, ob die Pflanze mit Wasser versorgt
 * werden muss, oder ob die Erde noch feucht genug ist.
 *
 * @author Maik Proba, Mat-Nr. 886125
 * Contact: maik.proba@hs-osnabrueck.de
 * 
 *  
 */


#include <M5Stack.h>

#include "Menu.h"
#include "MenuView.h"
#include "MenuController.h"

Menu menu;
MenuView menuView;
MenuController menuController(menu, menuView);


//Die Pinbezeichnungen für die Buttons lauten GPIO_NUM_39 (BtnA), GPIO_NUM_38 (BtnB) sowie GPIO_NUM_37 (BtnC).
uint8_t buttonA = GPIO_NUM_39;
uint8_t buttonB = GPIO_NUM_38;
uint8_t buttonC = GPIO_NUM_37; 


void buttonA_clicked(){
   menuController.vorherigerMenupunkt();
}

void buttonB_clicked(){
   menuController.setIsMenuVisible();
}

void buttonC_clicked(){
   menuController.naechsterMenupunkt();
}

void setup() {
   //M5Stack Init
   M5.begin();
   M5.Power.begin();
}

void loop() {
   //Menu aktualisieren
   menuController.updateView();
   //Nutzer wechselt Menupunkt
   //Wenn Button A gedrückt wird:
   attachInterrupt(buttonA, buttonA_clicked, RISING);

   //Wenn Button B gedrückt wird:
   attachInterrupt(buttonB, buttonB_clicked, RISING);

   //Wenn Button C (->) gedrückt wird:
   attachInterrupt(buttonC, buttonC_clicked, RISING);

   //delay(1000);
}

