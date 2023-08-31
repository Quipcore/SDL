//
// Created by felix on 2023-08-26.
//

#ifndef SDLGAME_DRAWIMAGESDL_H
#define SDLGAME_DRAWIMAGESDL_H

#include "SDL.h"

class drawImageSDL {
public:
    int run();
private:
    //Screen dimension constants
    const int SCREEN_WIDTH = 594;
    const int SCREEN_HEIGHT = 594;

    SDL_Window* gWindow = NULL;
    SDL_Surface* gScreenSurface = NULL;
    SDL_Surface* gHelloWorld = NULL;
    bool init();
    bool loadMedia();
    void close();
};


#endif //SDLGAME_DRAWIMAGESDL_H
