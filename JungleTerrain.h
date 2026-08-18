#ifndef JUNGLETERRAIN_H
#define JUNGLETERRAIN_H
#include "Terrain.h"

class JungleTerrain: public Terrain {
    public:
        JungleTerrain() {
            swim = false;
            walk = true;
            zipline = true;
            cycle = false;
        }
        string getDescription() {return "Jungle, jungle, jungle. Trees, plants and the like.\n";}
};

#endif //JUNGLETERRAIN_H
