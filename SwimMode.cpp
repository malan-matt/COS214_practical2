#include "SwimMode.h"
#include "Terrain.h"
#include "dialogue.h"
#include "BoatMode.h"
#include "Traveller.h"

#include <iostream>

void SwimMode::move(Traveller& traveller) {
    if (traveller.getTerrain().canSwim()) {
        std::cout << YELLOW << "You are now swimming to your destination\n" << RESET;
        wait_for_enter();
        //transition
        if (traveller.getEnergy() >= 30 || traveller.getMoney() >= 30) {
            std::cout << CYAN << "Would you like to continue swimming or transition to a different travel mode?\n";
            std::cout << " 1. Continue swimming (Cost: energy 30, money 0)\n" 
                      << " 2. Boat (Cost: energy 0, money 30)\n" << RESET;
            int transition;
            if (!(std::cin >> transition)) { //noninteger inputs
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << RED << "Invalid input, try again.\n" << RESET;
                wait_for_enter();
            }
            switch(transition){
                case 1:
                    if (traveller.getEnergy() >= 30) {
                        traveller.setEnergy(traveller.getEnergy() - 30);
                        std::cout << RED << "Energy -30\n" << RESET;
                        traveller_stats(traveller);
                        wait_for_enter();
                        std::cout << YELLOW << "\nYou keep swimming.\n" << RESET;
                        wait_for_enter();
                    }
                    else{
                        std::cout << RED << "You do not have enough energy, choose a different option.\n" << RESET;
                        wait_for_enter();
                    }
                    break;
                case 2:
                    if (traveller.getMoney() >= 30) {
                        traveller.setMode(new BoatMode());
                        traveller.move();
                    }
                    else{
                        std::cout << RED << "You do not have enough energy/money, choose a different option.\n" << RESET;
                        wait_for_enter();
                    }
                    break;
                default:
                    std::cout << RED << "Invalid input, try again.\n" << RESET;
                    wait_for_enter();
            }
        }
        else {
            death(traveller, traveller.getTerrain());
        }
    }
    else {
        std::cout << RED << "Swimming is not possible in this terrain.\n" << RESET;
        wait_for_enter();
    }
}