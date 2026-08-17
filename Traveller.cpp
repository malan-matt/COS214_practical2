#include "Traveller.h"
#include "WalkingMode.h"

Traveller::Traveller(Terrain& currentTerrain, int energy, int money, string name): currentMode(new WalkingMode()), currentTerrain(&currentTerrain), energy(energy), money(money), name(name){}

Traveller::~Traveller(){
    delete currentMode;
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

void Traveller::setTerrain(Terrain& newTerrain){
    currentTerrain = &newTerrain;
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

Terrain& Traveller::getTerrain() const{
    return *currentTerrain;
}

string Traveller::getName() const{
    return name;
}