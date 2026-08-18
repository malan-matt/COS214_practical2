#ifndef CITYNPC_H
#define CITYNPC_H

#include "NPC.h"

class CityNPC : public NPC {
    public:
        string greeting() { return "A busy business man with a busy man briefcase notices you.\n'...', he's a busy man after all\n"; };
        string information() { return "You try your best to look even busier than he.\nNo matter, he's too busy to notice.\n"; };
};

#endif //CITYNPC_H
