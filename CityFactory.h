#ifndef CITYFACTORY_H
#define CITYFACTORY_H

#include "CityObstacle.h"
#include "CityTerrain.h"
#include "CityNPC.h"
#include "BiomeFactory.h"

class CityFactory : public BiomeFactory {
    public:    
        NPC* buildNPC() {return new CityNPC(); }
        Terrain* buildTerrain() {return new CityTerrain();}
        Obstacle* buildObstacle() {return new CityObstacle();}
};

#endif //CITYFACTORY_H
