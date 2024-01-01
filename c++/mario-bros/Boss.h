#ifndef BOSS_H
#define BOSS_H

#include "CellContent.h"

class Boss : public CellContent {
    public:
        char interactWith(Mario *mario);
    private:
        bool beatBoss();
        char bossLose(Mario *mario);
        char bossWin(Mario *mario);
};

#endif