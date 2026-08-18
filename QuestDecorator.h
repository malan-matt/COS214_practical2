#ifndef QUESTDECORATOR_H
#define QUESTDECORATOR_H
#include "LocationDecorator.h"

class QuestboardDecorator : public PlaceDecorator {
    public:
        explicit QuestboardDecorator(Map* place) : PlaceDecorator(place) {}
        string describe() const override {
            return PlaceDecorator::describe() + " --- quest board: There's a board with jobs available, but you're a wayfarer not an adventurer.\n";
        }
};

class QuestDecorator : public PlaceDecorator {
    public:
        explicit QuestDecorator(Map* place) : PlaceDecorator(place) {}
        string describe() const override {
            return PlaceDecorator::describe() + " --- quest: You hear a cry coming from a building nearby. 'Not my problem lol', you selfishly think to yourself.\n";
        }
};

#endif
