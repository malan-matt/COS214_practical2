#ifndef OCEANOBSTACLE_H
#define OCEANOBSTACLE_H

#include "Obstacle.h"

class OceanObstacle: public Obstacle{
    public:    
        void description();
        void event(Traveller*);
        void event2(Traveller*);
};

void OceanObstacle::description(){
    std::cout << YELLOW << "WATER, water as far as the eye can see." << RESET
                << "\nYou see the water catch the light of the sun, and it's unlike anything you've seen before\n";
    wait_for_enter();
}

void OceanObstacle::event(Traveller* traveller){
    std::cout << "In the distance you see an " << YELLOW << "abandoned ship\n" << RESET;
    wait_for_enter();
    std::cout << "You manage to make your way to it.\nHowever it's loot has long been taken. Must've been pirates.\n";
    std::cout << MAGENTA << "WHAT IF THEY COME TO ROB US??\n" << RESET 
            << "You panic, and worry that they are just over the horizon.\n";
    wait_for_enter();
    std::cout << "but no one came...\n";
    wait_for_enter();
}

void OceanObstacle::event2(Traveller* traveller){}

#endif //OCEANOBSTACLE_H
