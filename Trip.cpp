#include "Trip.h"
#include "ShortestRoute.h"
#include "ScenicRoute.h"
#include "FastestRoute.h"
#include "dialogue.h"
#include <iostream>

Trip::Trip(RouteStrategy* strategy) : strategy(strategy) {}

Trip::Trip(const Trip& other)
    : strategy(other.strategy ? other.strategy->clone() : nullptr) {}

Trip& Trip::operator=(const Trip& other) {
    if (this != &other) {
        RouteStrategy* newStrategy = other.strategy ? other.strategy->clone() : nullptr;
        delete strategy;
        strategy = newStrategy;
    }
    return *this;
}

Trip::~Trip() {
    delete strategy;
}

void Trip::setStrategy(RouteStrategy* newStrategy) {
    if (newStrategy != strategy) {
        delete strategy;
        strategy = newStrategy;
    }
}

void Trip::chooseRoute(int energy, int money) {
    if (energy <= LOW_ENERGY) {
        setStrategy(new ShortestRoute());
    } else if (money >= HIGH_MONEY) {
        setStrategy(new ScenicRoute());
    } else {
        setStrategy(new FastestRoute()); 
    }
    plan();
}

void Trip::plan() const {
    if (!strategy) {
        std::cout << YELLOW << "No route strategy selected.\n" << RESET;
        wait_for_enter();
        return;
    }
    std::cout << YELLOW << "Your trip will use the " << strategy->name() << "\n" << RESET;
    wait_for_enter();
    strategy->findRoute();
} 