//
// Created by felix on 2023-08-26.
//

#include "drawImageSDL.h"
#include "SDL.h"
#include "cstdio"
#include "string"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

int drawImageSDL::run() {

    if(!init()) {
        printf("Failed to initialize!\n");
        return -1;
    }

    if(!loadMedia())
    {
        printf( "Failed to load media!\n" );
        return -2;
    }

    SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface,NULL);
    //Update the surface
    SDL_UpdateWindowSurface( gWindow );
    //Hack to get window to stay up
    SDL_Event e; bool quit = false; while(!quit){ while( SDL_PollEvent(&e ) ){ if(e.type == SDL_QUIT ) quit = true; } }

    //Free resources and close SDL
    close();
    return 0;
}

bool drawImageSDL::init() {
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

    if( gWindow == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }

    //Get window surface
    gScreenSurface = SDL_GetWindowSurface( gWindow );
    return true;
}

bool drawImageSDL::loadMedia() {
    const char *bmpPath = "../resources/helloWorld.bmp";
    //Load splash image
    gHelloWorld = SDL_LoadBMP( bmpPath );
    if( gHelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", bmpPath, SDL_GetError() );
        return false;
    }

    return true;
}

void drawImageSDL::close() {
    //Deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}
