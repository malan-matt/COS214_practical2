#include "Traveller.h"
#include "ZiplineMode.h"
#include "dialogue.h"

#include <iostream>

void ZiplineMode::move(Traveller& traveller) {
    traveller.setMoney(traveller.getMoney() - 30);
    std::cout << RED << "Money -30\n" << RESET;
    traveller_stats(traveller);
    wait_for_enter();
    std::cout << YELLOW << "You are now ziplining to your destination\n" << RESET; 
    wait_for_enter();
}