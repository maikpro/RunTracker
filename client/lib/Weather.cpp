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

#include "Weather.h"

Weather::Weather(String temperatur, String datum, String wochentag, String description, String city) {
    setTemperatur(temperatur);
    setDatum(datum);
    setWochentag(wochentag);
    setDesc(description);
    setCity(city);
}

Weather::Weather(String temperatur, String datum, String wochentag, String description) {
    setTemperatur(temperatur);
    setDatum(datum);
    setWochentag(wochentag);
    setDesc(description);
}



