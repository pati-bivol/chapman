#ifndef MARIO_H
#define MARIO_H

#include <string>
#include <iostream>
using namespace std;

class Mario {
    public:
        Mario(int L, int V, int N, ostream &log);
        void move();
        void spawn();
        void loseLife();
        void enemyDefeated();


        // mario's position in the game
        int level;
        int x;
        int y;
        int L;
        int PL;
        int coins;
        int N;
        int V;
        ostream &log;
        void printPreInteractionDetails();
        void printPostInteractionDetails(string str);

    private:
        void printStartingPosition();
        int consecutiveEnemyKills;
};

#endif