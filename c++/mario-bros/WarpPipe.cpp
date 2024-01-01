#include "WarpPipe.h"

char WarpPipe::interactWith(Mario *mario) {
    mario->printPreInteractionDetails();
    mario->printPostInteractionDetails("Mario found a warp pipe. ");
    mario->log << "Mario will warp. " << endl;
    mario->level++;
    mario->spawn();
    return 'w';
}