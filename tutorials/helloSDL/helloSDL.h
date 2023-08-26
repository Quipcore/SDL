//
// Created by felix on 2023-08-26.
//

#ifndef SDLGAME_HELLOSDL_H
#define SDLGAME_HELLOSDL_H

#include "SDL.h"

class helloSDL {
public:
    int run();
private:
    void sdlQuitProc(SDL_Window *window);
};


#endif //SDLGAME_HELLOSDL_H
