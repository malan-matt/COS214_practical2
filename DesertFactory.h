#ifndef DESERTFACTORY
#define DESERTFACTORY

#include "DesertNPC.h"
#include "BiomeFactory.h"

class DesertFactory : public BiomeFactory {
    public:    
        NPC* buildNPC() {return new DesertNPC(); };
        Terrain* buildTerrain() {return nullptr;};
};


#endif //DESERTFACTORY