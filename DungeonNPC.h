#ifndef DUNGNPC_H
#define DUNGNPC_H

#include "NPC.h"

class DungeonNPC : public NPC {
    public:
        string greeting() { return "No one was there to greet you.\n"; };
        string information() { return "You quietly listen to the silence in the halls\n"; };
};

#endif //CITYNPC_H
