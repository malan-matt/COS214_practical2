#include "WalkingMode.h"
#include "Terrain.h"
#include "dialogue.h"
#include <iostream>

void WalkingMode::move(Traveller& traveller) {
  
    traveller.setEnergy(traveller.getEnergy() - 5);
    
    if (traveller.getEnergy() > 5){
        if (traveller.getTerrain().canWalk()) {
            std::cout << "You are now walking to your destination\n";
            wait_for_enter();
            //transitions begin
            std::cout << CYAN << "Would you like to continue walking or transition to a different travel mode?\n";
            std::cout << " 1. Continue walking (Cost: energy 20, money 0)\n" 
                      << " 2. Cycle (Cost: energy 10, money 2)\n"
                      << " 3. Zipline (Cost: energy 0, money 30)\n" << RESET;
            int transition;
            std::getline(std::cin, transition);
            switch (transition) {
                case 1:
                    traveller.setEnergy(traveller.getEnergy() - 20);
                    std::cout << RED << ""
            }
        }
    }
    if (traveller.getEnergy() >= 10) {
        //cout?
        traveller.setMode(new BikingMode());
    }
}