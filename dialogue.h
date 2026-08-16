#ifndef DIALOGUE_H
#define DIALOGUE_H
#include "Traveller.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

void wait_for_enter(){
    std::cout << BLUE << "<<press enter to continue>>" << RESET;
    std::cin.ignore();
}

void traveller_stats(Traveller& traveller){
    std::cout << "Your current stats:\n";
    std::cout << YELLOW << "Energy: " << traveller.getEnergy()
              << "\nMoney: " << traveller.getMoney() << RESET;  
}

//You're welcome to edit this and make it more dramatic
void death(Traveller& traveller, Terrain& terrain){
    std::cout << RED << traveller.getName() << "'s energy has gone below zero.\n"
              << "You collapse to the ground\n"
              << "We will all be saddened by this death.\n"
              << "Game left incomplete." << RESET;
}

#endif