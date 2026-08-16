#include "Traveller.h"

Traveller::Traveller(TravelMode* currentMode, int energy, int money, string name): currentMode(currentMode), energy(energy), money(money), name(name){}

Traveller::~Traveller(){
    delete currentMode;
}

void Traveller::setMode(TravelMode* newMode){
    //IDK
    //delete currentMode;
    //currentMode = newMode;
}

void Traveller::move(){
    if (currentMode) {
        currentMode->move(*this);
    }
}