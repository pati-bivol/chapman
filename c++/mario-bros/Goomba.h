#ifndef GOOMBA_H
#define GOOMBA_H

#include "CellContent.h"

class Goomba : public CellContent {
    public:
        char interactWith(Mario *mario);
    private:
        bool beatGoomba();
        char goombaLose(Mario *mario);
        char goombaWin(Mario *mario);
};

#endif