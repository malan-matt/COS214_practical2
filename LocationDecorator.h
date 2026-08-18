#ifndef PLACEDECORATOR_H
#define PLACEDECORATOR_H

#include "Map.h"

class PlaceDecorator : public Map {
    public:
        PlaceDecorator(Map* place) : Map(place->getName()), component(place) {}
        ~PlaceDecorator() override {delete component;}
        void add(Map* child) override {component->add(child);}
        string describe() const override {return component->describe();}
    protected:
        Map* component;
};

#endif
