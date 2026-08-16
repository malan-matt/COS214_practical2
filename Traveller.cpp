#include "Traveller.h"

Traveller::Traveller(TravelMode* currentMode, Terrain* currentTerrain, int energy, int money, string name): currentMode(currentMode), currentTerrain(currentTerrain), energy(energy), money(money), name(name){}

Traveller::~Traveller(){
    delete currentMode;
    delete currentTerrain;
}

void Traveller::move(){
    if (currentMode) {
        currentMode->move(*this);
    }
}

void Traveller::setMode(TravelMode* newMode){
    if (newMode)
    {
        delete currentMode;
        currentMode = newMode;
    }
}

void Traveller::setTerrain(Terrain* newTerrain){
    if (newTerrain)
    {
        delete currentTerrain;
        currentTerrain = newTerrain;
    }
}

int Traveller::getEnergy() const{
    return energy;
}

int Traveller::getMoney() const {
    return money;
}

void Traveller::setEnergy(int newEnergy) {
    energy = newEnergy;
}

void Traveller::setMoney(int newMoney){
    money = newMoney;
}

Terrain* Traveller::getTerrain() const{
    return currentTerrain;
}

string Traveller::getName() const{
    return name;
}