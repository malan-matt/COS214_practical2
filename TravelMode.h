#ifndef TRAVELMODE_H
#define TRAVELMODE_H
#include <string>

class Traveller;

//Abstract
//State participant
class TravelMode {
    public:
    virtual ~TravelMode() = default;
    virtual void move(Traveller& traveller) = 0;
};

#endif