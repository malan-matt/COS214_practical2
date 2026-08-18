#ifndef OCEANTERRAIN_H
#define OCEANTERRAIN_H
#include "Terrain.h"

class OceanTerrain: public Terrain {
    public:
        OceanTerrain() {
            swim = true;
            walk = false;
            zipline = false;
            cycle = false;
        }
        string getDescription() {return "An ocean, lots of water. Not a lot of sand";}
};

#endif //OCEANTERRAIN_H
