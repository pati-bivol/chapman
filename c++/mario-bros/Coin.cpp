#include "Coin.h"

char Coin::interactWith(Mario *mario) {
    mario->printPreInteractionDetails();

    mario->coins++;
    if (mario->coins >= 20) {
        mario->V++;
        mario->coins = 0;
    }
    mario->printPostInteractionDetails("Mario collected a coin. ");
    mario->move();
    return 'x';
}

