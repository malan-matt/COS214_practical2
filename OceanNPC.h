#ifndef OCEANNPC_H
#define OCEANNPC_H

#include "NPC.h"

class OceanNPC : public NPC {
    public:
        string greeting() { return "There's an old sailor who speaks to you,\n'Woah there, you don't look like you belong here.'\nYou aren't exactly dressed like an ocean-goer.\n"; };
        string information() { return "He doesn't want to talk to you\n"; };
};

#endif //OCEANNPC_H
