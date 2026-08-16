#include "WalkingMode.h"
#include "Terrain.h"
#include <iostream>

void WalkingMode::move(Traveller& traveller) {
    std::cout << "Would you like to continue walking or transition to a different travel mode?/n
                1. Continue (uses 5 energy)
            "
    traveller.setEnergy(traveller.getEnergy() - 5);
    //transition
    if (traveller.getEnergy() > 5){
       
        if (traveller.getTerrain().getWalk()) {
            std::cout << "You are now walking to your destination\n";
        }
    
    }
    if (traveller.getEnergy() >= 10) {
        //cout?
        traveller.setMode(new BikingMode());
    }
}