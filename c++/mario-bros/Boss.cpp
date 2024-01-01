#include "Boss.h"

char Boss::interactWith(Mario *mario) {
    mario->printPreInteractionDetails();
    if (beatBoss()) {
        mario->printPostInteractionDetails("Mario encountered a boss and won. ");
        mario->log << "Mario will go to the next level. " << endl ;
        return bossWin(mario);
    } else {
        mario->printPostInteractionDetails("Mario encountered a boss and lost. ");
        mario->log << "Mario will stay put. " << endl ;
        return bossLose(mario);
    }
}

bool Boss::beatBoss() {
    int probability = rand() % 2;
    if (probability == 0) {
        return true;
    } else {
        return false;
    }
}

char Boss::bossLose(Mario *mario) {
    if (mario->PL >= 2) {
        mario->PL = 0;
    } else {
        mario->loseLife();
    }
    return 'b';
}

char Boss::bossWin(Mario *mario) {
    mario->level++;
    mario->spawn();
    return 'x';
}


