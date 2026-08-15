#ifndef TERRAIN_H
#define TERRAIN_H

#include <string>
using std::string;

class Terrain {
    //traits etc
    public:
        virtual string getDescription() = 0;
        virtual bool getSwim() = 0;
        virtual bool getRun() = 0;
        virtual bool getFly() = 0; 
    private:
        bool canSwim, canRun, canFly;
};

#endif //TERRAIN_H