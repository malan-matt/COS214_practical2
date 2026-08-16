#ifndef DESERTOBSTACLE_H
#define DESERTOBSTACLE_H

#include "Obstacle.h"

class DesertObstacle: public Obstacle{
    public:    
        void description();
        void event(Traveller*);
        void event2(Traveller*);
}

void DesertObstacle::description(){
    std::cout<<"\n" << YELLOW << "You stumble upon a temple, its walls covered in sand and its bricks showing centuries of erosion\n" << RESET;
    wait_for_enter();
    std::cout << "\n" << YELLOW << "You see a statue in the distance, an old king perhaps.\nIt is definitely intimidating, if you were opposing him, that would send you running with your tail between your legs.\n" <<RESET;
    wait_for_enter();
    std::cout << "\nHowever, his name must be long forgotten by now.\n";
    wait_for_enter();
}

void DesertObstacle::event(Traveller* traveller){
    std::cout << "A small idea grows: THERE'S HOARDS OF GOLD IN THERE!!!\n";
    std::cout << MAGENTA << "And hoards of spiders, skeletons and who knows what!\n" << RESET;
    wait_for_enter();
    std::cout << "You peer into the main entrance, a dark passage that seems to go on for eternity.\n";
    bool valid = false;
    char input;
    while (!valid){
        std::cout << CYAN << "Explore the mysterious temple? (y/n)\n" << RESET;    
        std::cin >> input;
        switch (input) {
            case 'Y':
            case 'y':
                std::cout<< "GIMME THAT MONEY! HERE I COME!\n";
                wait_for_enter();
                std::cout << "\nEntering the temple, you walk through cobwebs and stumble through dark hallways.\n";
                std::cout << "Surprisingly, there are plenty of torches in the further halls\n";
                std::cout << MAGENTA << "There's definitely something in here\n" << RESET;
                wait_for_enter();
                std::cout << "You stumble upon a room with a golden idol. It's the shape of the statue outside," 
                            << YELLOW << " small enough to put in your bag.\n" << RESET;
                wait_for_enter();
                std::cout << YELLOW << "\nI'M NOT BACKING DOWN NOW!\n" <<RESET;
                std::cout << "You swiftly grab the idol, and place it in your bag\n";
                wait_for_enter();
                std::cout << "\n...nothing happens?\n";
                wait_for_enter();
                std::cout << "\nA LOUD SCREECH SHAKES THE TEMPLE\n";
                std::cout << MAGENTA << "THERE IS SOMETHING HERE!!!\nI'M   T O A S T\n" << RESET;
                wait_for_enter();
                std::cout << "\nOnce you get your senses together, you quickly dash through the halls\n"
                            << "You don't get a chance to see whatever shook the temple, but you manage to get to the exit safely.\nLet's put this behind us," 
                                << MAGENTA <<" and not brag about desecrating a place of rest.\n" <<RESET;
                std::cout << YELLOW <<"Energy -15, Money +30 \n" << RESET;
                //TODO: INTERACT WITH TRAVELLER
                wait_for_enter();
                valid = true;
                break;
            case 'N':
            case 'n':
                std::cout << "It's obviously a trap! And I'm no gravedigger! And- and- I'm definitely NOT scared!\n";
                std::cout << "You decide to press on past the temple\n";
                wait_for_enter();
                valid = true;
                break;
            default:
                valid = false;
                std::cout << RED << "INVALID INPUT\n" << RESET;
                break;
        }
    }

}

void DesertObstacle::event2(Traveller* traveller){
    std::cout << "You stand at the base of the statue\n"
            << "The size is overwhelming, as if it becomes one with the skies above."
                <<"\nYou can't make out the kings features from here. But you read the inscription at the base.\n";
    wait_for_enter();
    std::cout << YELLOW <<"'Look on my works, ye Mighty, and despair!'"<<RESET
            <<"\nHowever there is nothing beside the statue. No works, only a lonesome king. Ruler of the sands which took everything away.\n";
    wait_for_enter();
    std::cout << "Goodbye nameless king.\n" << "You press on to the next region\n";
    wait_for_enter();
}


#endif //DESERTOBSTACLE