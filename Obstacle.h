#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Traveller.h"
#include "dialogue.h"

class Obstacle {
    public:
        void run(Traveller*);
        virtual void description() = 0;
        virtual void event(Traveller*) = 0;
        virtual void event2(Traveller*) = 0;
};

void Obstacle::run(Traveller* traveller){
 
    description();
    event(traveller);
    event2(traveller);

    if(traveller->getEnergy() <= 0){
        //traveller->death
    }

}

#endif //OBSTACLE_H