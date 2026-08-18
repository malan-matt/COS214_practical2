#ifndef MAP_H
#define MAP_H

#include <string>
using std::string;

class Map {
    public:
        Map(string name) {this->name = name;}
        virtual ~Map() = default;
        virtual string describe() const = 0;
        virtual void add(Map* child) { /*Returns nothing for location*/ }
        const string& getName() const { return name; }
    protected:
        string name;
};

#endif //MAP_H
