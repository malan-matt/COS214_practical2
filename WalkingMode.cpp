#include "WalkingMode.h"
#include "Terrain.h"
#include "dialogue.h"
#include <iostream>

//make somkething to check if traveller can do anything- otherwise stuck
void WalkingMode::move(Traveller& traveller) {
    if (traveller.getEnergy() > 5){
        if (traveller.getTerrain().canWalk()) {
            std::cout << YELLOW << "You are now walking to your destination\n" << RESET;
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
                    if (traveller.getEnergy() > 20)
                    {
                        traveller.setEnergy(traveller.getEnergy() - 20);
                        std::cout << RED << "Energy -20\n" << RESET;
                        traveller_stats(traveller, traveller.getTerrain());

                    }
                    else{
                        std::cout << "You do not have enough energy, choose a different option.\n";
                    }
                    break;
                case 2: 
                    if (traveller.getTerrain().canCycle) {
                        if (traveller.getEnergy() > 10 && traveller.getMoney() > 2)
                        {
                            traveller.setEnergy(traveller.getEnergy() - 10);
                            traveller.setEnergy(traveller.getMoney() - 2);
                            std::cout << YELLOW << "You are now cycling to your destination\n" << RESET;
                            std::cout << RED << "energy -20\n" << RESET;
                            traveller_stats(traveller, traveller.getTerrain());

                        }
                        else{
                            std::cout << "You do not have enough energy/money, choose a different option.\n";
                        }
                    }
                    else {
                        std::cout << YELLOW << "Cycling is not possible in this terrain.\n" << RESET;
                    }
                    break;
                case 3: 
                    if (traveller.getTerrain().canZipline) {
                        if (traveller.getMoney() > 30)
                        {
                            traveller.setEnergy(traveller.getMoney() - 30);
                            std::cout << YELLOW << "You are now ziplining to your destination\n" << RESET; //make more fun
                            std::cout << RED << "money -30\n" << RESET;
                            traveller_stats(traveller, traveller.getTerrain());

                        }
                        else{
                            std::cout << "You do not have enough money, choose a different option.\n";
                        }
                    }
                    else {
                        std::cout << YELLOW << "Ziplining is not possible in this terrain.\n" << RESET;
                    }
                    break;
                defualt:
                    std::cout << YELLOW << "Invalid input, try again.\n" << RESET;
            }
        }
        else {
            std::cout << YELLOW << "Walking is not possible in this terrain.\n" << RESET;
        }
    }
    // if (traveller.getEnergy() >= 10) {
    //     //cout?
    //     traveller.setMode(new BikingMode());
    // }
}