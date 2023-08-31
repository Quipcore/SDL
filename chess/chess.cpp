//
// Created by felix on 2023-08-26.
//

#include <cstdio>
#include "chess.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Quitting procedure. This need to be called before exiting in order to release resources
void chess::sdlQuitProc(SDL_Window *window) {
    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();
}

int chess::run(){
    //The window we'll be rendering to
    SDL_Window *window = NULL;

    //The surface contained by the window
    SDL_Surface *screenSurface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        sdlQuitProc(window);
        return -1;
    }

    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        sdlQuitProc(window);
        return -1;
    }

    //Get window surface
    screenSurface = SDL_GetWindowSurface(window);

    //Fill the surface white
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

    //Update the surface
    SDL_UpdateWindowSurface(window);


    printf("Window up!");

    //Hack to get window to stay up
    SDL_Event e;
    bool quit = false;
    while (!quit) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; }}
    sdlQuitProc(window);
    return 0;
}