#ifndef SWIMMODE_H
#define SWIMMODE_H
#include "TravelMode.h"

//Concrete state
class SwimMode : public TravelMode {
    public: 
        //getNextMode?
        void move(Traveller& traveller) override;
};

#endif