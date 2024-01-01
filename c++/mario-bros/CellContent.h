#ifndef CELL_CONTENT_H
#define CELL_CONTENT_H

#include "Mario.h"

class CellContent {
    public:
        virtual char interactWith(Mario *mario) = 0;
};

#endif