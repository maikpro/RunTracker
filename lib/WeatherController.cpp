#include "WeatherController.h"

WeatherController::WeatherController(String restUrl, Weather weatherModel, WeatherView weatherView){
    this->restUrl=restUrl;
    this->weatherModel=weatherModel;
    this->weatherView=weatherView;

    this->isHeute=true;
    this->isWoche=false;
}

void WeatherController::updateView(){
    if( this->isHeute ){
        httpGetHeute();
        this->weatherView.showViewHeute(this->weatherModel);
    } else if( this->isWoche ){
        httpGetWoche();
        this->weatherView.showViewWoche(this->weatherModel);
    }
    
}

void WeatherController::heute(){
    //heutiges Wetter anzeigen...
    this->isHeute=true;
    this->isWoche=false;
}

void WeatherController::woche(){
    //wetter der ganzen Woche anzeigen...
    this->isWoche=true;
    this->isHeute=false;
}

//"https://api.openweathermap.org/data/2.5/weather?q=osnabrueck&units=metric&appid=myKey"
void WeatherController::httpGetHeute(){
    //this->httpClient.begin("https://api.openweathermap.org/data/2.5/weather?q=osnabrueck&units=metric&appid=" + myApiKey);
    
    this->httpClient.begin(this->restUrl + "/weather/api/heute"); //REST API vom NodeJS Server
    int httpStatus = httpClient.GET();
    
    if(httpStatus == 200){
        String dataFromApi = httpClient.getString();
        this->weatherModel.setData(dataFromApi);
        this->weatherModel.parseJSONHeute(); //Temperatur erstmal auslesen...
    }

    httpClient.end();
}

void WeatherController::httpGetWoche(){
    //Wochen API auslesen!!
    this->httpClient.begin(restUrl + "/weather/api/woche"); //REST API vom NodeJS Server
    int httpStatus = httpClient.GET();
    
    if(httpStatus == 200){
        String dataFromApi = httpClient.getString();
        this->weatherModel.setData(dataFromApi);
        this->weatherModel.parseJSONWoche(); //Temperatur erstmal auslesen...
    }

    httpClient.end();
}