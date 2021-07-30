#include "RunController.h"

RunController::RunController(Timer timerModel, RunView runView){
    this->timerModel=timerModel;
    this->runView=runView;
}

void RunController::updateTime(){
    if( this->timerModel.getExecTime() < millis() && this->timerModel.getStart()){
      this->timerModel.updateTime(); //ACHTUNG NICHT GLEICHE METHODE!

      //Jede Sekunde aktualisieren, wenn Start true
      this->timerModel.setExecTime(millis() + 1000);
    }
}

void RunController::updateView(){
    if( this->timerModel.getStart() ){
        updateTime();
    }
    this->runView.showView(this->timerModel);
}



void RunController::buttonInteractions(uint8_t pinButtonA, uint8_t pinButtonB, uint8_t pinButtonC){
    //geht nicht...
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
    }

    //Hier müssen nun die GPS-Daten getrackt werden...
}

void RunController::pause(){
    this->timerModel.setStart(false);
}

void RunController::stop(){
    this->timerModel.setStop(true);
    this->timerModel.setStart(false);
}

