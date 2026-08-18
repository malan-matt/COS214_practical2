#ifndef CITYOBSTACLE_H
#define CITYOBSTACLE_H

#include "Obstacle.h"

class CityObstacle: public Obstacle{
    public:    
        void description();
        void event(Traveller*);
        void event2(Traveller*);
};

void CityObstacle::description(){
    std::cout << YELLOW << "You arrive in a bustling city\n" << RESET
                <<"The sky seems to disappear among the structures.\n";
    wait_for_enter();
}

void CityObstacle::event(Traveller* traveller){
    std::cout << YELLOW << "Buildings\n" << RESET;
    wait_for_enter();
    std::cout << "'There's too many buildings here.', You thinl to yourself\n";
    std::cout << MAGENTA << "The country is dying.\n" << RESET 
            << "'As in, the land is being overridden.', you find it necessary to clarify.\n";
    wait_for_enter();
    std::cout << "...\n";
    wait_for_enter();
    std::cout << "You didn't start this journey to spend your time " << YELLOW << "among the bricks!\n" << RESET;
    std::cout << "You are one with nature, you are truly different from the rest.\n";
    wait_for_enter();
    std::cout << "You see the " << MAGENTA << "infestation" << RESET 
        <<  " that structured society and rules bring.\nBut, eh, it works I guess.\n";
    wait_for_enter();
}

void CityObstacle::event2(Traveller* traveller){
    std::cout << YELLOW << "KEBAB STAND!\n" << RESET;
    wait_for_enter();
    std::cout << "It's been a hot minute since you've had one of those!\nBetter get some now, while you can!\n";
    wait_for_enter();
    if (traveller->getMoney() < 5){
        std::cout << "YOU'RE TOO BROKE FOR KEBABS!!!!!!!!!\n";
        wait_for_enter();
        return;
    } else {
        traveller->setMoney(traveller->getMoney() - 5);
        std::cout << YELLOW <<"You buy a kebab\n" <<RESET;
        wait_for_enter();
        std::cout << "It's delicious\n";
        std::cout << YELLOW <<"Money -5\n" << RESET;
    }
}

#endif //CITYOBSTACLE_H
