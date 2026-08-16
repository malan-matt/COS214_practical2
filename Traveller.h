#ifndef TRAVELLER_H
#define TRAVELLER_H
#include <string>
#include "TravelMode.h"
#include "Terrain.h"

using std::string;

//Player Character
//Context in state pattern
//maintains instance of state and delegates state specific requests to curr obj
class Traveller {
    public:
        Traveller(TravelMode* currentMode, int energy, int money, string name);
        ~Traveller();
        void move(); 
        void setMode(TravelMode* newMode);
        //Will potentially have to pass Terrain as parameter to move() to 
        //check possibility of travel eg Swim in desert
        int getEnergy() const;
        int getMoney() const;
        int setEnergy(int energy);
        int setMoney(int money);
        Terrain* getTerrain() const;
        Terrain* setTerrain(Terrain* newTerrain);
        string getName() const;
    private:
        string name;
        int money;
        int energy; 
        Terrain* currentTerrain;
        TravelMode* currentMode;
};

#endif //Traveller