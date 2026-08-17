#include "ShortestRoute.h"
#include "dialogue.h"
#include <iostream>

void ShortestRoute::findRoute() const {
    std::cout << RED << "Low energy levels\n" << RESET;
    std::cout << YELLOW << "Your feet are sore, looks like you better find a shortcut\n" << RESET;
    wait_for_enter();
}

std::string ShortestRoute::name() const {
    return "Shortest Route";
}

RouteStrategy* ShortestRoute::clone() const {
    return new ShortestRoute(*this);
}