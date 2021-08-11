#ifndef MYMQTTCLIENT_H
#define MYMQTTCLIENT_H

#include "Arduino.h"

#include <WiFiClient.h>
#include <PubSubClient.h>


class MyMQTTClient {
    private:
        PubSubClient pubSubClient;

    public:
        MyMQTTClient(){};
        MyMQTTClient(PubSubClient pubSubClient);

        void subscribe(char* clientID, char* topic);
        void publish(char* topic, char* payload);

        //callback wird nicht benötigt, da NodeJS Server die Daten aufnimmt und verarbeitet!
        //void callback(char* topic, byte* message, unsigned int length);
};

#endif