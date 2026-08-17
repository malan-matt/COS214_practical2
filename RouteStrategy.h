#ifndef ROUTE_STRATEGY_H
#define ROUTE_STRATEGY_H

#include <string>

//Abstract
//Strategy participant
class RouteStrategy {
    public:
        virtual ~RouteStrategy() = default;
        virtual void findRoute() const = 0;
        virtual std::string name() const = 0;
        virtual RouteStrategy* clone() const = 0;
};

#endif // ROUTE_STRATEGY_H