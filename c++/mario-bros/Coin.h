#ifndef COIN_H
#define COIN_H

#include "CellContent.h"
#include "Mario.h"

class Coin : public CellContent {
    public:
        char interactWith(Mario *mario);
};

#endif