#ifndef GAME_H
#define GAME_H

#include "World.h"
#include <fstream>

class Game {
public:
    Game(string inputFile, string outputFile);
    //~Game();
    void play();

private:
    World *world;
    Mario *mario;
    int L;
    int N;
    ofstream log;
    bool isGameOver();
};

#endif