#include "ClockController.h"

ClockController::ClockController(Timer myClock, ClockView clockView){
    this->myClock=myClock;
    this->clockView=clockView;
}

void ClockController::synchronization(){
    //https://www.timeapi.io/swagger/index.html
    this->httpClient.begin("https://www.timeapi.io/api/Time/current/zone?timeZone=Europe/Berlin");
    int httpStatus = httpClient.GET();
    if( httpStatus == 200 ){
        String dataFromTimeApi = httpClient.getString();
        this->myClock.setData(dataFromTimeApi);
        this->myClock.parseJSON();
        this->myClock.setIsSynced(true);
    }
}

void ClockController::updateTime(){
    //Synchronisiere die Zeit mit der Zeit aus dem GPS-Sensor
    if( !this->myClock.getIsSynced() ){
        synchronization();
    }

    if( this->myClock.getExecTime() < millis() ) {
        this->myClock.updateTime();
        this->myClock.setExecTime(millis() + 1000);
    }
}

void ClockController::updateView(){
    this->clockView.showView(this->myClock);
}
