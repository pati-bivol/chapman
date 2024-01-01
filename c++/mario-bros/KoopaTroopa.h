#ifndef KOOPATROOPA_H
#define KOOPATROOPA_H

#include "CellContent.h"

class KoopaTroopa : public CellContent {
public:
    char interactWith(Mario *mario);
private:
    bool beatKoopa();
    char koopaLose(Mario *mario);
    char koopaWin(Mario *mario);
};

#endif