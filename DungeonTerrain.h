#ifndef DungTERRAIN_H
#define DungTERRAIN_H
#include "Terrain.h"

class DungeonTerrain: public Terrain {
    public:
        DungeonTerrain() {
            swim = false;
            walk = true;
            zipline = false;
            cycle = false;
        }
        string getDescription() {return "The dungeon at the end of the journey.\n";}
};

#endif //CITYTERRAIN_H