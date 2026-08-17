#include "Traveller.h"
#include "BoatMode.h"
#include "dialogue.h"

#include <iostream>

void BoatMode::move(Traveller& traveller) {
    traveller.setMoney(traveller.getMoney() - 30);
    std::cout << RED << "Money -30\n" << RESET;
    wait_for_enter();
    traveller_stats(traveller);
    std::cout << YELLOW << "You are now on a boat to your destination\n" << RESET;
    wait_for_enter();
}