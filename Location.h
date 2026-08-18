#ifndef LOCATION_H
#define LOCATION_H

#include "Map.h"

class Location : public Map {
    public:
        Location(string name, string event): Map(name), event(event) {}
        string describe() const override {
            return "[" + name + "]\n" + event + "\n";
        }
    private:
        string event;
};

#endif
