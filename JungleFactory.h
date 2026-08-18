#ifndef JUNGLEFACTORY_H
#define JUNGLEFACTORY_H

#include "JungleObstacle.h"
#include "JungleTerrain.h"
#include "JungleNPC.h"
#include "BiomeFactory.h"

class JungleFactory : public BiomeFactory {
    public:    
        NPC* buildNPC() {return new JungleNPC(); }
        Terrain* buildTerrain() {return new JungleTerrain();}
        Obstacle* buildObstacle() {return new JungleObstacle();}
};

#endif //JUNGLEFACTORY_H
