#include "ClockController.h"

ClockController::ClockController(String restUrl, Timer myClock, ClockView clockView){
    this->restUrl=restUrl;
    this->myClock=myClock;
    this->clockView=clockView;
}

void ClockController::synchronization(){
    this->httpClient.begin(this->restUrl + "/time");
    int httpStatus = httpClient.GET();
    if( httpStatus == 200 ){
        String dataFromTimeApi = httpClient.getString();
        this->myClock.setData(dataFromTimeApi);
        this->myClock.parseJSON();
    }
}

void ClockController::updateTime(){
    synchronization();
}

void ClockController::updateView(){
    updateTime();
    this->clockView.showView(this->myClock);
}
