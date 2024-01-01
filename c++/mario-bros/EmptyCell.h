#ifndef EMPTY_CELL_H
#define EMPTY_CELL_H

#include "CellContent.h"

class EmptyCell : public CellContent {
public:
    char interactWith(Mario *mario);
};

#endif
