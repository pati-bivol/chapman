#include "World.h"


World::World(int L, int N, int coinRatio, int nothingRatio, int goombaRatio,
             int koopaRatio, int mushroomRatio, ostream &log) : L(L), N(N), log(log) {
    int ratios[] = {coinRatio, nothingRatio, goombaRatio, koopaRatio, mushroomRatio};

    World::world = new char **[L];
    for (int i=0; i<L; i++) {
        world[i] = new char *[N];
        for (int j=0; j<N; j++) {
            world[i][j] = new char[N];
            for (int k=0; k<N; k++) {
                world[i][j][k] = getRandomItem(ratios);
            }
        }
        insertWarpPipeAndBoss(i);
    }
    printWorld();
}

World::~World() {
    delete[] world;
}

void World::printWorld() {
    for (int k=0; k<L; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                log << world[k][i][j];
            }
            log << endl;
        }
        log << "==========" << endl;
    }
}

void World::interactWith(Mario *mario) {
    CellContent *content = getContent(mario);
    char newCellState = content->interactWith(mario);

    world[mario->level][mario->y][mario->x] = newCellState;
    print(mario);
}

CellContent* World::getContent(Mario *mario) {
    char c1 = world[0][1][1];
    int c2 = mario->level;
    int c3 = mario->y;
    int c4 = mario->x;
    char c = world[c2][c3][c4];
    switch (c) {
        case 'c':
            return new Coin();
        case 'm':
            return new Mushroom();
        case 'g':
            return new Goomba();
        case 'k':
            return new KoopaTroopa();
        case 'b':
            return new Boss();
        case 'w':
            return new WarpPipe();
        default:
            return new EmptyCell();
    }
}

char World::getRandomItem(int ratios[]) {
    char characterArray[] = {'c', 'x', 'g', 'k'};
    int random = rand() % 100;

    for (int i=0; i<4; i++) {
        if (random <= ratios[i]) {
            return characterArray[i];
        }
        random -= ratios[i];
    }
    return 'm';
}

void World::insertWarpPipeAndBoss(int level) {
    int bossX = rand() % N;
    int bossY = rand() % N;
    int warpPipeX;
    int warpPipeY;

    if (level != L) {
        do {
            warpPipeX = rand() % N;
        } while (warpPipeX == bossX);

        do {
            warpPipeY = rand() % N;
        } while (warpPipeY == bossY);

        world[level][warpPipeY][warpPipeX] = 'w';
    }
    world[level][bossY][bossX] = 'b';
}

void World::print(Mario *mario) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i == mario->x && j == mario->y) {
                log << 'H';
            } else {
                log << world[mario->level][i][j];
            }
        }
        log << endl;
    }
    log << "==========" << endl;
}