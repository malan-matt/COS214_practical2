#ifndef ZIPLINEMODE_H
#define ZIPLINEMODE_H
#include "TravelMode.h"

//Concrete state
class ZiplineMode : public TravelMode {
    public: 
        //getNextMode?
        void move(Traveller& traveller) override;
};

#endif