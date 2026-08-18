#ifndef REGION_H
#define REGION_H

#include "Map.h"
#include "dialogue.h"
#include <vector>
using std::vector;

class Region : public Map {
    public:
        Region(string name) : Map(name) {}
        ~Region() override {clear(); /*pretty much destructor*/}
        void add(Map* child) override {children.push_back(child);}
        void clear();
        string describe() const override;
    private:
        vector<Map*> children;
};

void Region::clear() {
    for (Map* child : children) delete child;
    children.clear();
}

string Region::describe() const { //prints all children, potentially recursively if it wishes for it
    string out = YELLOW + string("[") + name + "]\n" + RESET;
    for (Map* child : children) {
        out += child->describe();
    }
    return out;
}

#endif
