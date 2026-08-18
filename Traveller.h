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
        Traveller(TravelMode* startMode, Terrain& currentTerrain, int energy, int money, string name);
        ~Traveller();
        void move(); 
        void setMode(TravelMode* newMode);
        void setTerrain(Terrain& newTerrain);
        int getEnergy() const;
        int getMoney() const;
        void setEnergy(int newEnergy);
        void setMoney(int newMoney);
        Terrain& getTerrain() const;
        string getName() const;
    private:
        string name;
        int money;
        int energy; 
        Terrain* currentTerrain;
        TravelMode* currentMode;
};

#endif //Traveller