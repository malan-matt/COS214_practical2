#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>

using std::vector;
using std::string;

class Map {
    public:
        Map() = default;
        ~Map() = default;
        
    private:
};

class Region : public Map {
    public:
        Region(string);
        Map* getNextLocation();
    private:
        vector<Map*> children;
        string name;
};


class Location : public Map{

};

class LocationDecorator : public Map {

};

#endif //MAP_H