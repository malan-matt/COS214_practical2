//INCLUDES
/*
#include <iostream>
#include <string>

#include "Trip.h"
#include "FastestRoute.h"

#include "Traveller.h"
#include "DesertFactory.h"
#include "dialogue.h"

#include "Map.h"
#include "Location.h"
#include "Region.h"
#include "LocationDecorator.h"
#include "WeatherDecorator.h"
#include "TollDecorator.h"
#include "QuestDecorator.h"
#include "big_test.h"
#include "factory_test.h"
using std::string;

void strategy_test();
void npc_test();
void composite_decorator_test();

//MAIN
int main1(){
    factory_tests();
    strategy_test();
    composite_decorator_test();
    npc_test();
    wait_for_enter();
       try{
    runAllTests();
    } catch (...){
        exit(0);
    }
    return 0;
}

void npc_test(){
    BiomeFactory* fact = new DesertFactory();
    NPC* npc = fact->buildNPC();

    std::cout << npc->greeting();
    std::cout << npc->information();

}

void composite_decorator_test() {

    Region* world = new Region("World");
    Region* desert = new Region("Desert");
    desert->add(new Location("Campfire", "campfire"));
    desert->add(new Location("Dune", "sand"));
    desert->add(new TollDecorator(
                    new Location("Checkpoint", "A wooden gate blocks the path ahead.")));

    desert->add(new QuestDecorator(
                    new BadWeatherDecorator(
                        new TollDecorator(
                            new Location("Watchtower", "Tower")))));

    world->add(desert);

    Region* ocean = new Region("Ocean");
    ocean->add(new GoodWeatherDecorator(
                    new Location("Reef", "Colorful coral stretches beneath the clear water.")));
    ocean->add(new QuestboardDecorator(
                    new Location("Harbor", "Ships creak gently against the docks.")));

    world->add(ocean);

    Region* cove = new Region("Coral Cove");
    cove->add(new Location("Tidepool", "Tiny fish dart between the rocks."));
    ocean->add(cove);

    std::cout << "=== Initial map ===\n";
    std::cout << world->describe();

    Map* asBase = world;
    std::cout << "\n=== Same tree, accessed only through Map* ===\n";
    std::cout << asBase->describe();

    std::cout << "\n=== Clearing Desert, then rebuilding it ===\n";
    desert->clear();  
    desert->add(new Location("Oasis", "A shimmering pool of water breaks up the endless sand."));
    std::cout << world->describe();

    std::cout << "\n=== Clearing World entirely ===\n";
    world->clear();
    std::cout << world->describe();
    delete world;

    std::cout << "\nAll memory freed.\n";
}




void strategy_test() {
    Trip trip(new FastestRoute()); //default 

    trip.chooseRoute(20, 50);  //low energy 
    trip.chooseRoute(50, 80);  //high money 
    trip.chooseRoute(50, 50);  //mid

}

*/