#include "Goomba.h"

char Goomba::interactWith(Mario *mario) {
    char result;
    mario->printPreInteractionDetails();
    if (beatGoomba()) {
        mario->printPostInteractionDetails("Mario encountered a goomba and won. ");
        result =  goombaWin(mario);
    } else {
        mario->printPostInteractionDetails("Mario encountered a goomba and lost. ");
        result = goombaLose(mario);
    }
    mario->move();
    return result;
}

bool Goomba::beatGoomba() {
    int probability = rand() % 10;

    if (probability >= 8) {
        return true;
    } else {
        return false;
    }
}

char Goomba::goombaWin(Mario *mario) {
    mario->enemyDefeated();
    return 'x';
}

char Goomba::goombaLose(Mario *mario) {
    if (mario->PL <= 0) {
        mario->loseLife();
    } else {
        mario->PL--;
    }
    return 'g';
}