#ifndef WARPPIPE_H
#define WARPPIPE_H
#include "CellContent.h"

class WarpPipe : public CellContent {
    public:
        char interactWith(Mario *mario);
};

#endif