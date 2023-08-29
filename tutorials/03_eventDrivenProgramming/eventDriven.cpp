//
// Created by felix on 2023-08-26.
//

#include "eventDriven.h"
#include "SDL.h"
#include "cstdio"
int eventDriven::run() {

    if(!init()) {
        printf("Failed to initialize!\n");
        close();
        return -1;
    }

    if(!loadMedia())
    {
        printf( "Failed to load media!\n" );
        close();
        return -2;
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    while (!quit){
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        //Apply the image
        SDL_BlitSurface(gXOut, NULL, gScreenSurface, NULL );

        //Update the surface
        SDL_UpdateWindowSurface( gWindow );
    }

    close();
    return 0;
}

bool eventDriven::init() {
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

bool eventDriven::loadMedia() {
    const char *bmpPath = "../resources/x.bmp";
    //Load splash image
    gXOut = SDL_LoadBMP(bmpPath );
    if(gXOut == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", bmpPath, SDL_GetError() );
        return false;
    }

    return true;
}

void eventDriven::close() {
    //Deallocate surface
    SDL_FreeSurface(gXOut );
    gXOut = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}
