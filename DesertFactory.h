#ifndef DESERTFACTORY
#define DESERTFACTORY

#include "DesertObstacle.h"
#include "DesertTerrain.h"
#include "DesertNPC.h"
#include "BiomeFactory.h"

class DesertFactory : public BiomeFactory {
    public:    
        NPC* buildNPC() {return new DesertNPC(); }
        Terrain* buildTerrain() {return new DesertTerrain();}
        Obstacle* buildObstacle() {return new DesertObstacle();}
};


#endif //DESERTFACTORY