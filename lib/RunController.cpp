#include "RunController.h"

RunController::RunController(Timer timerModel, GPS gps, MyMQTTClient myMQTTClient, RunView runView){
    this->timerModel=timerModel;
    this->gps=gps;
    this->myMQTTClient=myMQTTClient;
    this->runView=runView;
}

void RunController::updateTime(){
    if( this->timerModel.getExecTime() < millis() && this->timerModel.getStart()){
      this->timerModel.updateTime(); //ACHTUNG NICHT GLEICHE METHODE!

      //Jede Sekunde aktualisieren, wenn Start true
      this->timerModel.setExecTime(millis() + 1000);
    }
}

void RunController::updateGPS(){
    this->gps.updateAll(); //aktuallisiert alle wichtigen GPS-Werte (Koordinaten, Zeit, Datum,...)
}

void RunController::sendGPSData(){
    //GPS-Daten werden nur bei Start des Timers gesendet!
    char* topic = "m5stackGps";
    this->myMQTTClient.subscribe("runtracker-m5stack", topic);
    
    //gps Koordinaten auslesen und in ein Buffer stecken => in JSON-Format!
    char gpsData[512];
    sprintf(gpsData, "{ \"gpsLat\": %.6f, \"gpsLng\": %.6f, \"date\": \"%02d.%02d.%02d\", \"time\": \"%02d:%02d:%02d\" }", this->gps.getLat(), this->gps.getLng(), this->gps.getDate().tag, this->gps.getDate().monat, this->gps.getDate().jahr, this->gps.getTime().h+2, this->gps.getTime().min, this->gps.getTime().sec);
    this->myMQTTClient.publish(topic, gpsData);
}

//Marker setzen wenn Runde beendet!
void RunController::endGPSData(){
    if(this->gps.getIsTracking()){
        char* topic = "m5stackGps";
        this->myMQTTClient.subscribe("runtracker-m5stack", topic);
        
        char* gpsEnd = "{ \"status\": 999 }";
        //sprintf(gpsEnd, "{ \"status\": %d }", 123);
        this->myMQTTClient.publish(topic, gpsEnd);
        this->gps.setIsTracking(false);
    }
}

void RunController::updateView(){
    updateGPS();
    if( this->timerModel.getStart() ){
        this->gps.setIsTracking(true);
        //updateTime(); wird generell in main geupdated!
        sendGPSData();
    }

    if( this->timerModel.getStop()){
        endGPSData();
    }

    this->runView.showView(this->timerModel, this->gps);
}

void RunController::start(){
    //Wenn vorher gestoppt wurde, resette den Timer
    if(this->timerModel.getStop()){
        this->timerModel.reset();
    }
    //Wenn erneut auf Start geklickt wird, pausiere den Timer
    else if(this->timerModel.getStart()){
        pause();
    } 
    //Ansonsten starte einfach den Timer
    else{
        this->timerModel.setStart(true);
        //this->gps.setIsTracking(true);
    }
}

void RunController::pause(){
    this->timerModel.setStart(false);
}

void RunController::stop(){
    this->timerModel.setStop(true);
    this->timerModel.setStart(false);
}

