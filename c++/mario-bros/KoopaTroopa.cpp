#include "KoopaTroopa.h"

char KoopaTroopa::interactWith(Mario *mario) {
    char result;
    mario->printPreInteractionDetails();

    if (beatKoopa()) {
        mario->printPostInteractionDetails("Mario encountered a koopa and won. ");
        result = koopaWin(mario);
    } else {
        mario->printPostInteractionDetails("Mario encountered a koopa and lost. ");
        result = koopaLose(mario);
    }

    mario->move();
    return result;
}

bool KoopaTroopa::beatKoopa() {
    int probability = rand() % 100;

    if (probability >= 65) {
        return true;
    } else {
        return false;
    }
}

char KoopaTroopa::koopaWin(Mario *mario) {
    mario->enemyDefeated();
    return 'x';
}

char KoopaTroopa::koopaLose(Mario *mario) {
    if (mario->PL <= 0) {
        mario->loseLife();
    } else {
        mario->PL--;
    }
    return 'k';
}