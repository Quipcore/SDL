#define SDL_MAIN_HANDLED

#include "chess.h"
#include "tutorials/02_drawImage/drawImageSDL.h"

int main(int argc, char *args[]) {
    //chess::run();
    drawImageSDL drawImageSDL;
    drawImageSDL.run();
    return 0;
}