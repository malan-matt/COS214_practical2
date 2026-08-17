#include "ScenicRoute.h"
#include "dialogue.h"
#include <iostream>

void ScenicRoute::findRoute() const {
    std::cout << RED << "High money levels\n" << RESET;
    std::cout << YELLOW << "You can afford to take your time and enjoy the views\n" << RESET;
    wait_for_enter();
}

std::string ScenicRoute::name() const {
    return "Scenic Route";
}

RouteStrategy* ScenicRoute::clone() const {
    return new ScenicRoute(*this);
}