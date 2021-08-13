#ifndef RUNCONTROLLER_H
#define RUNCONTROLLER_H

#include "Arduino.h"
#include <M5Stack.h>

#include "Timer.h" //Modell
#include "GPS.h" //Modell2
#include "RunView.h" //View

#include "MyMQTTClient.h"//MQTT Broker

class RunController {
    private:
        Timer timerModel;
        GPS gps;
        MyMQTTClient myMQTTClient;
        RunView runView;
        bool isRunVisible;

    public:
        RunController(Timer timerModel, GPS gps, MyMQTTClient myMQTTClient, RunView runView);
        void updateTime();
        void updateGPS();
        void sendGPSData();
        void endGPSData();
        void updateView();

        //Buttons
        void start();
        void pause();
        void stop();
};

#endif