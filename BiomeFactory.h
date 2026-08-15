#ifndef BIOMEFACTORY_H
#define BIOMEFACTORY_H

#include "NPC.h"
#include "Terrain.h"

class BiomeFactory {
    public:
        BiomeFactory() = default;
        virtual ~BiomeFactory() = default;
        virtual NPC* buildNPC() = 0;
        virtual Terrain* buildTerrain() = 0;
};

#endif //BIOMEFACTORY