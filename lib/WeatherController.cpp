#include "WeatherController.h"

#include <M5Stack.h> //ZUM TESTEN von httpGet methode

#include "apiKey.h"

WeatherController::WeatherController(Weather weatherModel, WeatherView weatherView){
    this->weatherModel=weatherModel;
    this->weatherView=weatherView;
}

void WeatherController::updateView(){
    this->weatherView.showView(this->weatherModel);
}

void WeatherController::heute(){
    //heutiges Wetter anzeigen...
}

void WeatherController::woche(){
    //wetter der ganzen Woche anzeigen...
}

//"https://api.openweathermap.org/data/2.5/weather?q=osnabrueck&units=metric&appid=myKey"
void WeatherController::httpGet(){
    this->httpClient.begin("https://api.openweathermap.org/data/2.5/weather?q=osnabrueck&units=metric&appid=" + myApiKey);
    int httpStatus = httpClient.GET();
    
    if(httpStatus == 200){
        String dataFromApi = httpClient.getString();
        this->weatherModel.setData(dataFromApi);
        this->weatherModel.parseJSON(); //Temperatur erstmal auslesen...

        //Anzeigen
        M5.Lcd.clearDisplay();
        M5.Lcd.setCursor(10,10);
        M5.Lcd.setTextSize(1);
        M5.Lcd.println(this->weatherModel.getData());
        M5.Lcd.println(this->weatherModel.getTemperatur());
    }

    httpClient.end();
}