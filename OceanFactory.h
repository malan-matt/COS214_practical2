#ifndef OCEANFACTORY_H
#define OCEANFACTORY_H

#include "OceanObstacle.h"
#include "OceanTerrain.h"
#include "OceanNPC.h"
#include "BiomeFactory.h"

class OceanFactory : public BiomeFactory {
    public:    
        NPC* buildNPC() {return new OceanNPC(); }
        Terrain* buildTerrain() {return new OceanTerrain();}
        Obstacle* buildObstacle() {return new OceanObstacle();}
};

#endif //OCEANFACTORY_H
