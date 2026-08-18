#ifndef TOLLDECORATOR_H
#define TOLLDECORATOR_H
#include "LocationDecorator.h"

class TollDecorator : public PlaceDecorator {
    public:
        explicit TollDecorator(Map* place) : PlaceDecorator(place) {}
        string describe() const override {
            return PlaceDecorator::describe() + " --- toll: You see a toll booth, best avoid it to keep your pockets full.\n";
        }
};
#endif
