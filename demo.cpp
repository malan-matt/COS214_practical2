#include <iostream>
#include <string>

#include "Trip.h"
#include "FastestRoute.h"
#include "Traveller.h"
#include "DesertFactory.h"
#include "CityFactory.h"
#include "dialogue.h"
#include "Map.h"
#include "Location.h"
#include "Region.h"
#include "DungeonFactory.h"
#include "LocationDecorator.h"
#include "WeatherDecorator.h"
#include "TollDecorator.h"
#include "QuestDecorator.h"
#include "OceanFactory.h"

using std::string;


int main(){
    std::cout<< "WELCOME TO WAYFARER\n" 
        <<"Your journey will take you to a many lands\n==========================\n\n";
    wait_for_enter();
 

    BiomeFactory* factory = new CityFactory();
    Terrain* terrain= factory->buildTerrain();
    NPC* currentNPC = factory->buildNPC();
    Traveller* traveller = new Traveller(terrain, 100, 50, "DesertExplorer");


    std::cout << currentNPC->greeting();
    wait_for_enter();
    std::cout << currentNPC->information();
    wait_for_enter();

 
    Region* world = new Region("World");
    Region* city = new Region("City");
    Map* decoratedCity = new TollDecorator(new QuestDecorator(city));
    world->add(decoratedCity);
 
    Location* buildingLoc = new Location(
        "Building",
        "A small building with a notice board out front."
    );
    Map* decoratedBuilding = new QuestboardDecorator(buildingLoc);
    world->add(decoratedBuilding);
 
    std::cout << world->describe();
 
    world->clear();

    delete factory;
    factory = new OceanFactory();
    delete terrain;
    terrain = factory->buildTerrain();

    try{
        //
        // ADD TRAVEL AND STATE HERE
        //
    } catch (...){

        // Clean up everything allocated before the exception
        world->clear();

        delete currentNPC;
        delete terrain;
        delete factory;
        delete world;
        delete traveller;

        return 0;
    }


 
    Region* ocean = new Region("Ocean");
    ocean->add(new Location("Waves", terrain->getDescription()));
    world->add(ocean);
 
    Obstacle* obstacle = factory->buildObstacle();
    obstacle->run(traveller);
    delete obstacle;
 
    std::cout << world->describe();
    world->clear();

    delete factory;
    factory = new DungeonFactory();
    delete terrain;
    terrain = factory->buildTerrain();

    try{
        //
        // ADD TRAVEL AND STATE HERE
        //
    } catch (...){

        // Clean up everything allocated before the exception
        world->clear();

        delete currentNPC;
        delete terrain;
        delete factory;
        delete world;
        delete traveller;

        return 0;
    }

    obstacle = factory->buildObstacle();
    obstacle->run();

    delete obstacle;


    delete currentNPC;
    delete terrain;
    delete factory;
    delete world;       
    delete traveller;
 
    return 0;
}