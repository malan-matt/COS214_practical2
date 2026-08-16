#ifndef TERRAIN_H
#define TERRAIN_H

#include <string>
using std::string;

class Terrain {
    //traits etc
    public:
        virtual Terrain() = default;
        virtual ~Terrain() = dafault;
        virtual string getDescription() = 0;
        virtual bool canSwim() = 0;
        virtual bool canRun() = 0;
        virtual bool canFly() = 0; 
        virtual bool canCycle() = 0;
    private:
        bool swim, run, fly, cycle;
};

#endif //TERRAIN_H