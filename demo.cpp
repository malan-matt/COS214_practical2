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

using std::string;


int main(){
    std::cout<< "WELCOME TO WAYFARER\n" 
        <<"Your journey will take you to a many lands\n==========================\n\n";
    wait_for_enter();

    
 

    BiomeFactory* cityFactory = new CityFactory();
    CityTerrain CityTerrain;
    Traveller* traveller = new Traveller(CityTerrain, 100, 50, "DesertExplorer");

    NPC* cityNPC = cityFactory->buildNPC();
    std::cout << cityNPC->greeting();
    wait_for_enter();
    std::cout << cityNPC->information();
    wait_for_enter();

    delete cityNPC;
    delete cityFactory;
 
    Region* world = new Region("World");
 
    Region* city = new Region("City");
    Map* decoratedCity = new TollDecorator(new QuestDecorator(city));
    world->add(decoratedCity);
 
    Location* buildingLoc = new Location("Building", "A small building with a notice board out front.");
    Map* decoratedBuilding = new QuestboardDecorator(buildingLoc);
    world->add(decoratedBuilding);
 
    std::cout << world->describe();
 
    world->clear();
    //
    // ADD TRAVEL AND STATE HERE
    //
    BiomeFactory* desertFactory = new DesertFactory();
    Terrain* desertTerrain = desertFactory->buildTerrain();
 
    Region* desert = new Region("Desert");
    desert->add(new Location("Terrain", desertTerrain->getDescription()));
    world->add(desert);
 
    Obstacle* desertObstacle = desertFactory->buildObstacle();
    desertObstacle->run(traveller);
    delete desertObstacle;
 
    std::cout << world->describe();

    delete desertTerrain;
    delete desertFactory;

    //
    // Travel STATE STRATEGY HERERE
    //
 
    delete world;       
    delete traveller;
 
    return 0;
}