//
// Created by felix on 2023-08-26.
//

#ifndef SDLGAME_CHESS_H
#define SDLGAME_CHESS_H

#include "SDL.h"

class chess {
public:
    static int run();
private:

    static void sdlQuitProc(SDL_Window *window);
};



#endif //SDLGAME_CHESS_H
