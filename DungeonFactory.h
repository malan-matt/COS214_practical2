#ifndef DUNGFACTORY_H
#define DUNGFACTORY_H

#include "DungeonObstacle.h"
#include "DungeonTerrain.h"
#include "DungeonNPC.h"
#include "BiomeFactory.h"

class DungeonFactory : public BiomeFactory {
    public:    
        NPC* buildNPC() {return new DungeonNPC(); }
        Terrain* buildTerrain() {return new DungeonTerrain();}
        Obstacle* buildObstacle() {return new DungeonObstacle();}
};

#endif //CITYFACTORY_H
