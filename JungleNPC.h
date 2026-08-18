#ifndef JUNGLENPC_H
#define JUNGLENPC_H

#include "NPC.h"

class JungleNPC : public NPC {
    public:
        string greeting() { return "It's a monkey?\n*Monkey noises*, it proudly emits while scratching it's round stomach\n"; };
        string information() { return "You try your best to converse with it.\nIt doesn't seem interested in your profound knowledge and wise words\n"; };
};

#endif //JUNGLENPC_H
