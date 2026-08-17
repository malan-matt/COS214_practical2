#ifndef SHORTEST_ROUTE_H
#define SHORTEST_ROUTE_H
#include "RouteStrategy.h"

//concrete strat
class ShortestRoute : public RouteStrategy {
    public:
        void findRoute() const override;
        std::string name() const override;
        RouteStrategy* clone() const override;
};
#endif