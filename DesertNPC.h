#ifndef DESERTNPC
#define DESERTNPC

#include "NPC.h"

class DesertNPC : public NPC {
    public:
        string greeting() { return "A friendly desert dweller approaches you.\n 'Welcome to the desert! I hope you packed a lot of water.' they chuckle.\n"; };
        string information() { return "You engage in conversation\n 'The desert is a harsh place, not many folks are fond of the sand. Quite course and rough, eh?'\nYou're clearly not the first traveller to come through here\n"; } ;
};

#endif //DESERTNPC