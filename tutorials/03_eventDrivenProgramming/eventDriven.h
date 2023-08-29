//
// Created by felix on 2023-08-26.
//
#ifndef SDLGAME_EVENTDRIVEN_H
#define SDLGAME_EVENTDRIVEN_H

#include "SDL.h"

class eventDriven {
public:
    int run();
private:
    SDL_Window* gWindow = NULL;
    SDL_Surface* gScreenSurface = NULL;
    SDL_Surface* gXOut = NULL;
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    bool init();
    bool loadMedia();
    void close();
};


#endif //SDLGAME_EVENTDRIVEN_H
