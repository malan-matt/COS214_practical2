#ifndef BOATMODE_H
#define BOATMODE_H
#include "TravelMode.h"

//Concrete state
class BoatMode : public TravelMode {
    public: 
        //getNextMode?
        void move(Traveller& traveller) override;
};

#endif