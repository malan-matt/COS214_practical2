#ifndef DESERTTERRAIN_H
#define DESERTTERRAIN_H
#include "Terrain.h"

class DesertTerrain: public Terrain {
    public:
        DesertTerrain() {
            swim = false;
            walk = true;
            zipline = false;
            cycle = true;
        }
        string getDescription() {return "A desert, lots of sand. Not a lot of water.";}
};


#endif