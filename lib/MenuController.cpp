#include "MenuController.h"

MenuController::MenuController(Menu menuModel, MenuView menuView){
    this->menuModel=menuModel;
    this->menuView=menuView;
}

void MenuController::updateView(){
    bool isMenuVisible = this->menuModel.getIsMenuVisible();
    if( isMenuVisible ){
        this->menuView.showMenu(this->menuModel.getCurrentId());
    } /*else{
        this->menuView.changeView(this->menuModel.getCurrentId(), this->menuModel.getIMenuItem());
    }*/
}

void MenuController::naechsterMenupunkt(){
    int currentId = this->menuModel.getCurrentId();
    if(currentId == 3){
        currentId = 0;
    } else{
        currentId++;
    }
    this->menuModel.setCurrentId( currentId );
}

void MenuController::vorherigerMenupunkt(){
    int currentId = this->menuModel.getCurrentId();
    if(currentId == 0){
        currentId = 3;
    } else{
        currentId--;
    }
    this->menuModel.setCurrentId( currentId );
}

void MenuController::setIsMenuVisible(){
    bool isMenuVisible = this->menuModel.getIsMenuVisible();
    this->menuModel.setIsMenuVisible(!isMenuVisible);
}

bool MenuController::getIsMenuVisible(){
    bool isMenuVisible = this->menuModel.getIsMenuVisible();
    return isMenuVisible;
}

int MenuController::getCurrentId(){
    int currentId = this->menuModel.getCurrentId();
    return currentId;
}