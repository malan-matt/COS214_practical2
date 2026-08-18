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
#include "WalkingMode.h"
#include "SwimMode.h"

using std::string;


int main(){
    std::cout<< "WELCOME TO WAYFARER\n" 
        <<"Your journey will take you to a many lands\n==========================\n\n";
    wait_for_enter();
 

    BiomeFactory* factory = new CityFactory();
    Terrain* terrain= factory->buildTerrain();
    NPC* currentNPC = factory->buildNPC();
    TravelMode* startMode = new WalkingMode();
    Traveller* traveller = new Traveller(startMode, *terrain, 100, 50, "DesertExplorer");
    terrain->getDescription();

    //Route strategy
    Trip trip(new FastestRoute()); 
    trip.chooseRoute(traveller->getEnergy(), traveller->getMoney()); 

    //State strategy
    traveller_stats(*traveller);
    traveller->move();

    std::cout << GREEN << "You have arrived.\n" << RESET;
    wait_for_enter();


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
    traveller->setTerrain(*terrain);

    Region* ocean = new Region("Ocean");
    ocean->add(new Location("Waves", terrain->getDescription()));
    world->add(ocean);
 
    Obstacle* obstacle = factory->buildObstacle();
    obstacle->run(traveller);
    delete obstacle;
 
    std::cout << world->describe();
    world->clear();

    //Route strategy
    traveller->setMoney(traveller->getMoney() + 30); 
    trip.chooseRoute(traveller->getEnergy(), traveller->getMoney()); 
    
    //State strategy
    traveller->setMode(new SwimMode());
    traveller_stats(*traveller);
    traveller->move();

    std::cout << GREEN << "\nYou have arrived.\n" << RESET;
    wait_for_enter();

    delete factory;
    factory = new DungeonFactory();
    delete terrain;
    terrain = factory->buildTerrain();
    traveller->setTerrain(*terrain);
    
    obstacle = factory->buildObstacle();
    obstacle->run(traveller);

    delete obstacle;
 
    // Clean up remaining allocations
    delete traveller;
    delete currentNPC;
    delete world;
    delete terrain;
    delete factory;
 
    return 0;
}