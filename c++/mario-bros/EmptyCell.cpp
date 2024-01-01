#include "EmptyCell.h"

char EmptyCell::interactWith(Mario *mario) {
    mario->printPreInteractionDetails();
    mario->printPostInteractionDetails("Mario visited an empty space. ");
    mario->move();
    return 'x';
}
