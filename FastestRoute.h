#ifndef FASTEST_ROUTE_H
#define FASTEST_ROUTE_H
#include "RouteStrategy.h"

class FastestRoute : public RouteStrategy {
    public:
        void findRoute() const override;
        std::string name() const override;
        RouteStrategy* clone() const override;
};
#endif