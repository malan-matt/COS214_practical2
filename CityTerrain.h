#ifndef CITYTERRAIN_H
#define CITYTERRAIN_H
#include "Terrain.h"

class CityTerrain: public Terrain {
    public:
        CityTerrain() {
            swim = false;
            walk = true;
            zipline = true;
            cycle = true;
        }
        string getDescription() {return "Buildings et al., 2026";}
};

#endif //CITYTERRAIN_H
