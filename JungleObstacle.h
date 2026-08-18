#ifndef JUNGLEOBSTACLE_H
#define JUNGLEOBSTACLE_H

#include "Obstacle.h"

class JungleObstacle: public Obstacle{
    public:    
        void description();
        void event(Traveller*);
        void event2(Traveller*);
};

void JungleObstacle::description(){
    std::cout << YELLOW << "You arrive in a humid jungle.\n" << RESET
                <<"You can hear all sorts of animals around you.\n";
    wait_for_enter();
    std::cout << "You wonder where you could get a nice steak here.\n";
    wait_for_enter();
}

void JungleObstacle::event(Traveller* traveller){
    std::cout << "In the distance you see a " << YELLOW << "tree house\n" << RESET;
    wait_for_enter();
    std::cout << "You manage to make your way to it.\nHowever it's ladder has been torn down.\n";
    std::cout << MAGENTA << "This poor tree has been taken advantage of.\n" << RESET 
            << "What a weird thought.\n";
    wait_for_enter();
    std::cout << "After some internal dialogue, you're convinced the tree would've liked to be lived in.\n";
    wait_for_enter();
    std::cout << "You're so sure of it, that you decide to " << YELLOW << "take a nap at the base of the tree\n" << RESET;
    std::cout << "You get comfy and slowly drift to sleep\n";
    wait_for_enter();
    std::cout << "Despite the ticks, snakebite and definite " << MAGENTA << "MALARIA" << RESET 
        <<  " you got during the night...\nYou feel well rested\n";
    std::cout << YELLOW <<"Energy +20\n" << RESET;
    wait_for_enter();
}

void JungleObstacle::event2(Traveller* traveller){
    std::cout << "A steak would be really good right now\n";
    wait_for_enter();
    std::cout << "You're fully aware that this train of thought is not gonna produce a steak\n";
    wait_for_enter();
    std::cout<<"But a steak would be reeallllyyyy good right now\n";
    wait_for_enter();
    std::cout<< "You press on\n";
    wait_for_enter();
}

#endif //JUNGLEOBSTACLE_H
