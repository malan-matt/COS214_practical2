#include "Traveller.h"
#include "CycleMode.h"
#include "dialogue.h"

#include <iostream>

void CycleMode::move(Traveller& traveller) {
    traveller.setEnergy(traveller.getEnergy() - 10);
    traveller.setMoney(traveller.getMoney() - 2);
    std::cout << RED << "Energy -10, Money -2\n" << RESET;
    wait_for_enter();
    traveller_stats(traveller);
    std::cout << YELLOW << "You are now cycling to your destination\n" << RESET;
    wait_for_enter();
}