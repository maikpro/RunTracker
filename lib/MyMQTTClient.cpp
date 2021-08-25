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

#include "MyMQTTClient.h"

MyMQTTClient::MyMQTTClient(PubSubClient pubSubClient){
    this->pubSubClient=pubSubClient;

    const char* mqtt_server = "broker.mqttdashboard.com";
    this->pubSubClient.setServer(mqtt_server, 1883);
    //client.setCallback(callback);
}

void MyMQTTClient::subscribe(char* clientID, char* topic){
    if (!pubSubClient.connected()) {
        while (!pubSubClient.connected()) {
            //Aufbauen einer Verbindung
            if (this->pubSubClient.connect(clientID)) {
                //Subscribe
                this->pubSubClient.subscribe(topic);
            }
        }
    }
    pubSubClient.loop();
};

void MyMQTTClient::publish(char* topic, char* payload){
    //"m5stackGps", "hello world"
    this->pubSubClient.publish(topic, payload);
    //this->pubSubClient.publish("m5stackGps", "hello world");
}

/*
void MyMQTTClient::callback(char* topic, byte* message, unsigned int length){
  //konvertiere Byte* in ein String
  char newMessage[length + 1]; //Buffer erstellen
  memcpy(newMessage, message, length); //Copy byte Message in den Buffer
  newMessage[length] = '\0'; // zum Schluss Enden Strings mit '\0'
}*/