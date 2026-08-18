#ifndef DIALOGUE_H
#define DIALOGUE_H
#include "Traveller.h"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

inline void wait_for_enter(){
    std::cout << BLUE << "<<press enter to continue>>" << RESET;
    std::cin.ignore();
}

inline void traveller_stats(Traveller& traveller){
    std::cout << "\nYour current stats:\n";
    std::cout << YELLOW << "Energy: " << traveller.getEnergy()
              << "\nMoney: " << traveller.getMoney() << "\n" << RESET;  
}

//You're welcome to edit this and make it more dramatic
inline void death(Traveller& traveller, Terrain& terrain){
    std::cout << RED << traveller.getName() << "'s energy has gone below zero or too low to continue.\n"
              << "You collapse to the ground\n"
              << "We will all be saddened by this death.\n"
              << "Game left incomplete." << RESET;
    throw 1;
}

#endif