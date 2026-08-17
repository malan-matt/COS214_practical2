#include "WalkingMode.h"
#include "Terrain.h"
#include "dialogue.h"
#include "CycleMode.h"
#include "ZiplineMode.h"
#include "Traveller.h"

#include <iostream>

void WalkingMode::move(Traveller& traveller) {
    // check if traveller has enough money or energy to do anything
    if ((traveller.getMoney() >= 30)
        || (traveller.getEnergy() >= 10 && traveller.getMoney() >= 2)
        || (traveller.getEnergy() >= 20) ) {
            if (traveller.getTerrain().canWalk()) {
                std::cout << YELLOW << "You are now walking to your destination\n" << RESET;
                wait_for_enter();
                //transitions begin
                bool validTransition = false;
                int failCheck = 0; //Important
                while (!validTransition){
                    std::cout << CYAN << "Would you like to continue walking or transition to a different travel mode?\n";
                    std::cout << " 1. Continue walking (Cost: energy 20, money 0)\n" 
                              << " 2. Cycle (Cost: energy 10, money 2)\n"
                              << " 3. Zipline (Cost: energy 0, money 30)\n" << RESET;
                    int transition;
                    if (!(std::cin >> transition)) { //noninteger inputs
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << RED << "Invalid input, try again.\n" << RESET;
                        wait_for_enter();
                        continue;
                    }
                    switch (transition) {
                        case 1:
                            if (traveller.getEnergy() >= 20)
                            {
                                traveller.setEnergy(traveller.getEnergy() - 20);
                                std::cout << RED << "Energy -20\n" << RESET;
                                traveller_stats(traveller);
                                wait_for_enter();
                                std::cout << YELLOW << "You keep walking.\n" << RESET;
                                wait_for_enter();
                                validTransition = true;
                            }
                            else{
                                std::cout << RED << "You do not have enough energy, choose a different option.\n" << RESET;
                                wait_for_enter();
                                failCheck++;
                            }
                            break;
                        case 2: 
                            if (traveller.getTerrain().canCycle()) {
                                if (traveller.getEnergy() >= 10 && traveller.getMoney() >= 2)
                                {
                                    traveller.setMode(new CycleMode());
                                    traveller.move();
                                    validTransition = true;
        
                                }
                                else{
                                    std::cout << RED << "You do not have enough energy/money, choose a different option.\n" << RESET;
                                    wait_for_enter();
                                    failCheck++;
                                }
                            }
                            else {
                                std::cout << RED << "Cycling is not possible in this terrain.\n" << RESET;
                                wait_for_enter();
                                failCheck++;
                            }
                            break;
                        case 3: 
                            if (traveller.getTerrain().canZipline()) {
                                if (traveller.getMoney() >= 30)
                                {
                                    traveller.setMode(new ZiplineMode());
                                    traveller.move();
                                    validTransition = true;
        
                                }
                                else{
                                    std::cout << RED << "You do not have enough money, choose a different option.\n" << RESET;
                                    wait_for_enter();
                                    failCheck++;
                                }
                            }
                            else {
                                std::cout << RED << "Ziplining is not possible in this terrain.\n" << RESET;
                                wait_for_enter();
                                failCheck++;
                            }
                            break;
                        default:
                            std::cout << RED << "Invalid input, try again.\n" << RESET;
                            wait_for_enter();
                    }
                    if (failCheck) //checks if traveller doesn't have enough resources for whats allowed in the terrain
                    {
                        death(traveller, traveller.getTerrain());
                    }
                } 
            }
            else {
                std::cout << RED << "Walking is not possible in this terrain.\n" << RESET;
                wait_for_enter();
            }
    }
    else {
        death(traveller, traveller.getTerrain());
    }
}