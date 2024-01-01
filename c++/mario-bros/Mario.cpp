#include "Mario.h"

Mario::Mario(int L, int V, int N, ostream &log) : L(L), V(V), N(N), log(log) {
    PL = 0;
    coins = 0;
    level = 0;
    x = 0;
    y = 0;

    spawn();
    printStartingPosition();
}

void Mario::spawn() {
    y = rand() % N;
    x = rand() % N;
}

void Mario::move() {
    int probability = rand() % 4;
    log << "Mario will move ";
    switch (probability) {
        case 0:
            log << "LEFT." << endl;
            y--;
            break;
        case 1:
            log << "RIGHT." << endl;
            y++;
            break;
        case 2:
            log << "UP." << endl;
            x++;
            break;
        default:
            log << "DOWN." << endl;
            x--;
            break;
    }

    // wrapping around
    if (x < 0) {
        x = N - 1;
    }
    if (y < 0) {
        y = N - 1;
    }
    if (y >= N) {
        y = 0;
    }
    if (x >= N) {
        x = 0;
    }

    log << "==========" << endl;
}

void Mario::loseLife() {
    V--;
    consecutiveEnemyKills = 0;
}

void Mario::enemyDefeated() {
    consecutiveEnemyKills++;

    if (consecutiveEnemyKills == 7) {
        V++;
        consecutiveEnemyKills = 0;
    }
}


void Mario::printStartingPosition() {
    log << "Mario is starting in position: (" << y << "," << x << ")" << endl;
    log << "==========" << endl;
}

void Mario::printPreInteractionDetails() {
    log << "Level: " << level << ". " <<
    "Mario is at position: (" << y << "," << x << "). " <<
    "Mario is at power level: " << PL << ". ";
}

void Mario::printPostInteractionDetails(string str) {
    log << str << "Mario has " << V << " lives left. " <<
    "Mario has " << coins << " coins. ";
}

