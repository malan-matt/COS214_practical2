#ifndef DungOBSTACLE_H
#define DungOBSTACLE_H

#include "Obstacle.h"

class DungeonObstacle: public Obstacle{
    public:    
        void description();
        void event(Traveller*);
        void event2(Traveller*);
};

void DungeonObstacle::description(){
    std::cout << YELLOW << "You arrive at a quiet Dungeon\n" << RESET
                <<"This is your final stop\n";
    wait_for_enter();
}

void DungeonObstacle::event(Traveller* traveller){
    std::cout << YELLOW << "Cold bricks line the walls\n" << RESET;
    wait_for_enter();
    std::cout << "No one has been here for a while.\n";
    std::cout << MAGENTA << "Not even a trace.\n" << RESET 
            << "As you walk the corridors, you finally stumble upon a gold laden door.\n";
    wait_for_enter();
    std::cout << "...\n";
    wait_for_enter();
    std::cout << "As you reach for the handle, you suddenly realise...\nThis is so " << YELLOW << "much extra work for 4 marks.\n" << RESET;
    wait_for_enter();
}

void DungeonObstacle::event2(Traveller* traveller){
    std::cout << YELLOW << "The End\n" << RESET;
    std::cout << "Thanks for playing!\n";
}

#endif //CITYOBSTACLE_H
