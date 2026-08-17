#ifndef TERRAIN_H
#define TERRAIN_H

#include <string>
using std::string;

class Terrain {
    //traits etc
    public:
        Terrain() = default;
        virtual ~Terrain() = default;
        virtual string getDescription() = 0;
        bool canSwim() {return swim;}
        bool canWalk() {return walk;}
        bool canZipline() {return zipline;}
        bool canCycle() {return cycle;}
    private:
        bool swim, walk, zipline, cycle;
};

#endif //TERRAIN_H