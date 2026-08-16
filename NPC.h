#ifndef NPC_H
#define NPC_H

#include <string>
using std::string;

class NPC{
    public:
        virtual string greeting() =0;
        virtual string information() =0;
};

#endif //NPC