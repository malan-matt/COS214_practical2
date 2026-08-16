#ifndef TRAVELMODE_H
#define TRAVELMODE_H
#include <string>
#include "Traveller.h"

//Abstract
//State participant
class TravelMode {
    public:
    virtual ~TravelMode() = default;
    virtual void move(Traveller& traveller) = 0;
    virtual TravelMode getNextMode() const = 0;
};

#endif