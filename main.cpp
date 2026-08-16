//INCLUDES
#include <iostream>
#include <string>

#include "Traveller.h"
#include "DesertFactory.h"

using std::string;

void npc_test();

//MAIN
int main(){

    npc_test();
    /*
    
    std::cout << "Welcome to Wayfarer!!!\n\n" << "Enter name: ";
    string playerName;
    std::getline(std::cin, playerName);

    std::cout<<"\n\nWelcome to your journey, " << name << "\n\n"; 

    bool activeGame = true;
    while(activeGame){
        // 1 Create world biome (Abstract Factory)
        // 2 Generate regions (Composite and Decorator)
        // 3 Place player at root region
        // 4 Give player options, (list locations at current region)
        // 5 if player wishes to move on, present the options of travel (Strategy, State)
        // 6 Make a check to see if the player takes a loss on travel
        // rinse and repeat or smthng
    }
    return 0;

    */
}

void npc_test(){
    BiomeFactory* fact = new DesertFactory();
    NPC* npc = fact->buildNPC();

    std::cout << npc->greeting();
    std::cout << npc->information();

}