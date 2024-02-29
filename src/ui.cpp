#include "ui.h"
#include <iostream>
#include <SDL.h>
#include <SDL2/SDL_image.h>

bool UserInterface::init() {
    // Initialization flag
    bool succes = true;

    // Initialise SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not be initialized! SDL_Error: " << SDL_GetError() << std::endl;
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
            // Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags) & imgFlags)) {
                std::cout << "SDL_image could not be initialized SDL_Error: " << SDL_GetError() << std::endl;
                succes = false;
            }
            else {
                // Get main window surface
                mainScrSurface = SDL_GetWindowSurface(mainWindow);
            }
        }
    }

    return succes;
}

SDL_Surface* UserInterface::loadSurface(std::string imgPath) {
    // Final optimized image
    SDL_Surface* optimizedSurface = NULL;
    
    // Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(imgPath.c_str());
    if(loadedSurface == NULL)
        std::cout << "Unable to load image " << imgPath << " SDL_Error: " << SDL_GetError() << std::endl;
    else {
        // Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface(loadedSurface, mainScrSurface->format, 0);
        if(optimizedSurface == NULL)
            std::cout << "Unable to optimize image " << imgPath << " SDL_Error: " << SDL_GetError() << std::endl;

        // Get rid of the old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return optimizedSurface;
}

bool UserInterface::loadMedia() {
    // Loading succes flag
    bool succes = true;

    // Load image
    backgroundSurface = loadSurface(backgroundImgPath);
    if(backgroundSurface == NULL) {
        std::cout << "Unable to load image! SDL_Error: " << SDL_GetError() << std::endl;
        succes = false;
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

            // Apply the image
            SDL_BlitSurface(backgroundSurface, NULL, mainScrSurface, NULL);

            // Update the surface
            SDL_UpdateWindowSurface(mainWindow);
        }
    } 

    return error;
}
