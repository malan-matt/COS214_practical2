#ifndef TRAVELLER_H
#define TRAVELLER_H
#include <string>

using std::string;

//Player Character
//Context in state pattern
class Traveller {
    public:
        Traveller(string);
        ~Traveller();
        bool move(); 
        void setMove(string);
        //Will potentially have to pass Terrain as parameter to move() to 
        //check possibility of travel eg Swim in desert
    private:
        string name;
        float money;
        float energy;
        //STATE* moveState;
};

#endif //Traveller