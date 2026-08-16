#ifndef WALKINGMODE_H
#define WALKINGMODE_H
#include "TravelMode.h"

//Concrete state
class WalkingMode : public TravelMode {
    public: 
        //getNextMode?
        void move(Traveller& traveller) override;
};

#endif