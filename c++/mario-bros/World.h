#ifndef WORLD_H
#define WORLD_H

#include "CellContent.h"
#include "Mario.h"
#include "Coin.h"
#include "Boss.h"
#include "Mushroom.h"
#include "KoopaTroopa.h"
#include "Goomba.h"
#include "EmptyCell.h"
#include "WarpPipe.h"

class World {
    public: 
        World(int L, int N, int coinRatio, int nothingRatio, int goombaRatio,
              int koopaRatio, int mushroomRatio, ostream& log);
        ~World();
        void printWorld();
        void print(Mario *mario);
        void interactWith(Mario *mario);

    private:
        int L;
        int N;
        char ***world;
        ostream &log;
        CellContent * getContent(Mario *mario);
        char getRandomItem(int ratios[]);
        void insertWarpPipeAndBoss(int level);
};

#endif