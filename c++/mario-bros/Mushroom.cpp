#include "Mushroom.h"

char Mushroom::interactWith(Mario *mario) {
    mario->printPreInteractionDetails();
    if (mario->PL < 2) {
        mario->PL++;
    }
    mario->printPostInteractionDetails("Mario ate a mushroom. ");
    mario->move();
    return 'x';
}