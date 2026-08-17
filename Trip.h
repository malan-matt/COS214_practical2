#ifndef TRIP_H
#define TRIP_H

#include "RouteStrategy.h"
#include <string>

// Context participant.
class Trip {
    public:
        Trip(RouteStrategy* strategy);
        Trip(const Trip& other);
        Trip& operator=(const Trip& other);
        ~Trip();
        void setStrategy(RouteStrategy* newStrategy);
        void chooseRoute(int energy, int money);
        void plan() const; // delegates to whatever strategy is currently set
    private:
        static const int LOW_ENERGY = 30;
        static const int HIGH_MONEY = 70;
        RouteStrategy* strategy; //Maintains ref to strategy obj
};

#endif // TRIP_H