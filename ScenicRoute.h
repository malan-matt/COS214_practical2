#ifndef SCENIC_ROUTE_H
#define SCENIC_ROUTE_H
#include "RouteStrategy.h"

class ScenicRoute : public RouteStrategy {
    public:
        void findRoute() const override;
        std::string name() const override;
        RouteStrategy* clone() const override;
};
#endif