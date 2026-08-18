#ifndef WEATHERDECORATOR_H
#define WEATHERDECORATOR_H
#include "LocationDecorator.h"

class GoodWeatherDecorator : public PlaceDecorator {
    public:
        explicit GoodWeatherDecorator(Map* place) : PlaceDecorator(place) {}
        string describe() const override {
            return PlaceDecorator::describe() + " --- weather: You feel uplifted by the pleasent air\n";
        }
};

class BadWeatherDecorator : public PlaceDecorator {
    public:
        explicit BadWeatherDecorator(Map* place) : PlaceDecorator(place) {}
        string describe() const override {
            return PlaceDecorator::describe() + " --- weather: The weather could be worse, but it's definitely not great\n";
        }
};

#endif
