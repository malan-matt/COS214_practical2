#include "FastestRoute.h"
#include "dialogue.h"
#include <iostream>

void FastestRoute::findRoute() const {
    std::cout << RED << "Moderate energy and money levels\n" << RESET;
    std::cout << YELLOW << "Your spirits are high and your pockets are subfull\nYou get the feeling something is following you. You're paranoid\nNo detours, No dawdling\nLet's get to this destination\n" << RESET;
    wait_for_enter();
}

std::string FastestRoute::name() const {
    return "Fastest Route";
}

RouteStrategy* FastestRoute::clone() const {
    return new FastestRoute(*this);
}