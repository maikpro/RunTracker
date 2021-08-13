#include "SettingsController.h"

SettingsController::SettingsController(SettingsView settingsView){
    this->settingsView=settingsView;
}

void SettingsController::updateView(){
    this->settingsView.showView();
}
