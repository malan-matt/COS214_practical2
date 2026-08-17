#ifndef CYCLEMODE_H
#define CYCLEMODE_H
#include "TravelMode.h"

//Concrete state
class CycleMode : public TravelMode {
    public: 
        //getNextMode?
        void move(Traveller& traveller) override;
};

#endif