#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "CellContent.h"

class Mushroom : public CellContent {
    public:
        char interactWith(Mario *mario);
};

#endif