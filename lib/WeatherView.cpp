#include "WeatherView.h"

#include "WeatherIcons.h"

WeatherView::WeatherView(int id, String title){
    this->id=id;
    this->title=title;
}

void WeatherView::showViewHeute(Weather weather){
    //Position Icon
    int pos_icon_x = 120;
    int pos_icon_y = 20;
    int icon_size = 64;

    //Position Data
    int pos_x_data = 110;
    int pos_y_data = 100;
    
    //Anzeigen
    M5.Lcd.clearDisplay(WHITE);
    M5.Lcd.setTextColor(BLACK);
    M5.Lcd.setCursor(pos_x_data, pos_y_data);
    M5.Lcd.setTextSize(3);
    
    //Anzeige Temperatur
    M5.Lcd.println(weather.getTemperatur());
    //Anzeige Beschreibung des Wetters
    pos_y_data=pos_y_data+40;
    M5.Lcd.setCursor(pos_x_data, pos_y_data);
    M5.Lcd.println(weather.getDesc());
    //Anzeige Stadtnamen
    pos_y_data=pos_y_data+40;
    M5.Lcd.setCursor(pos_x_data, pos_y_data);
    M5.Lcd.println(weather.getCity());

    
    //Per "Main" kann das Wetter identifiziert werden und dementsprechend wird das passende Wettersymbol angezeigt:
    /*Weitere Wetter Bedingungen:
    https://openweathermap.org/weather-conditions 
        "Clouds": Wolken Icon
        "Clear": Sonne Icon
        "Rain": RegenWolken
        "Thunderstorm": Blitz mit Wolke
        "Snow": Wolke mit Schneeflocken
    */
    if(weather.getDesc() == "Clouds"){
        M5.Lcd.drawBitmap(pos_icon_x, pos_icon_y, icon_size, icon_size, (uint16_t *) clouds);
    } else if( weather.getDesc() == "Clear" ){
        M5.Lcd.drawBitmap(pos_icon_x, pos_icon_y, icon_size, icon_size, (uint16_t *) sun);
    } else if( weather.getDesc() == "Rain" ){
        M5.Lcd.drawBitmap(pos_icon_x, pos_icon_y, icon_size, icon_size, (uint16_t *) rain);
    } else if( weather.getDesc() == "Thunderstorm" ){
        M5.Lcd.drawBitmap(pos_icon_x, pos_icon_y, icon_size, icon_size, (uint16_t *) storm);
    } else if( weather.getDesc() == "Snow" ){
        M5.Lcd.drawBitmap(pos_icon_x, pos_icon_y, icon_size, icon_size, (uint16_t *) snow);
    }

    //Steuerung
    M5.Lcd.setTextSize(1);
    M5.Lcd.setCursor(30, 220);
    M5.Lcd.println("Heute");
    M5.Lcd.setCursor(140, 220);
    M5.Lcd.println("Zurück");
    M5.Lcd.setCursor(240, 220);
    M5.Lcd.println("Woche");

    
}

void WeatherView::showViewWoche(Weather weather){
    //Anzeigen
    M5.Lcd.clearDisplay(WHITE);
    M5.Lcd.setTextColor(BLACK);

    //Wetter Wochenansicht
    int x_pos=10;
    int y_pos=50;
    int icon_size = 64;

    //ES WERDEN NUR 4 Tage angezeigt wegen der Display-Größe!
    for(int i=0; i < weather.getWocheTemperaturen().size()-1; i++){
        //Wetter Icons
        String description = weather.getWocheDescription().at(i);
        if(description == "Clouds"){
        M5.Lcd.drawBitmap(x_pos, y_pos, icon_size, icon_size, (uint16_t *) clouds);
        } else if( description == "Clear" ){
            M5.Lcd.drawBitmap(x_pos, y_pos, icon_size, icon_size, (uint16_t *) sun);
        } else if( description == "Rain" ){
            M5.Lcd.drawBitmap(x_pos, y_pos, icon_size, icon_size, (uint16_t *) rain);
        } else if( description == "Thunderstorm" ){
            M5.Lcd.drawBitmap(x_pos, y_pos, icon_size, icon_size, (uint16_t *) storm);
        } else if( description == "Snow" ){
            M5.Lcd.drawBitmap(x_pos, y_pos, icon_size, icon_size, (uint16_t *) snow);
        }

        //Datum anzeigen
        M5.Lcd.setCursor(x_pos, y_pos+70);
        M5.Lcd.println( weather.getWocheDatum().at(i) );

        //Temperatur anzeigen
        M5.Lcd.setCursor(x_pos, y_pos+90);
        M5.Lcd.println( weather.getWocheTemperaturen().at(i) + "°C");
        
        

        x_pos = x_pos + 80;
    }

    //Steuerung
    M5.Lcd.setTextSize(1);
    M5.Lcd.setCursor(40, 220);
    M5.Lcd.println("Heute");
    M5.Lcd.setCursor(140, 220);
    M5.Lcd.println("Zurück");
    M5.Lcd.setCursor(240, 220);
    M5.Lcd.println("Woche");
}