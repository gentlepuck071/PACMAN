#include "ui.h"
#include <iostream>
#include <SDL.h>

bool UserInterface::init() {
    // Initialization flag
    bool succes = true;

    // Initialise SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not be initialized! SLD_Error: " << SDL_GetError() << std::endl;
        succes = false;
    }
    else {
        // Create main window
        mainWindow = SDL_CreateWindow("Main Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
        if(mainWindow == NULL) {
            std::cout << "Main Window could not be created! SLD_Error: " << SDL_GetError() << std::endl;
            succes = false;
        }
        else {
            // Get main windows surface
            mainScrSurface = SDL_GetWindowSurface(mainWindow);
        }
    }

    return succes;
}

bool UserInterface::loadMedia() {
    // Loading succes flag
    bool succes = true;

    // Load image
    backgroundSurface = SDL_LoadBMP(backgroundImgPath.c_str());
    if(backgroundSurface == NULL) {
        std::cout << "Unable to load image! SDL_Error: " << SDL_GetError() << std::endl;
        succes = false;
    }
    else {
        if((mainScrSurface == NULL) || (mainWindow == NULL)) {
            std::cout << "Window not initialized! SDL_Error: " << SDL_GetError() << std::endl;
            succes = false;
        }
        else {
            // Apply the image
            SDL_BlitSurface(backgroundSurface, NULL, mainScrSurface, NULL);

            // Update the surface
            SDL_UpdateWindowSurface(mainWindow);
        }
    }

    return succes;
}

void UserInterface::close() {
    // Deallocate image surface
    SDL_FreeSurface(backgroundSurface);
    backgroundSurface = NULL;

    // Destroy main window
    SDL_DestroyWindow(mainWindow);
    mainWindow = NULL;

    // Quit SDL subsystem
    SDL_Quit();
}

int UserInterface::gameLoop() {
    // Error flag
    int error = 0;

    if((mainWindow == NULL) || (mainScrSurface == NULL) || (backgroundSurface == NULL)) {
        std::cout << "UI elements not initialized! SDL_Error: " << SDL_GetError() << std::endl;
        error = 1;
    }
    else {
        // Event loop
        SDL_Event e;
        bool quit = false;
        while(!quit) {
            while(SDL_PollEvent(&e)) {
                if(e.type == SDL_QUIT)
                    quit = true;
            }
        }
    } 

    return error;
}
