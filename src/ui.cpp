#include "ui.h"
#include <iostream>

bool ui_init() {
    // Initialization flag
    bool succes = true;

    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not be initialized! SLD_Error: " << SDL_GetError() << std::endl;
        succes = false;
    }
    else {
        // Create main window
        main_window = SDL_CreateWindow("Main Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
        if(main_window == NULL) {
            std::cout << "Main Window could not be created! SLD_Error: " << SDL_GetError() << std::endl;
            succes = false;
        }
        else {
            // Get main windows surface
            main_screenSurface = SDL_GetWindowSurface(main_window);
        }
    }

    return succes;
}

bool ui_loadMedia() {
    // Loading succes flag
    bool succes = true;

    std::cout << imgPath << std::endl;

    // Load image
    img_screenSurface = SDL_LoadBMP(imgPath.c_str());
    if(img_screenSurface == NULL) {
        std::cout << "Unable to load image! SDL_Error: " << SDL_GetError() << std::endl;
        succes = false;
    }

    return succes;
}

void ui_close() {
    // Deallocate image surface
    SDL_FreeSurface(img_screenSurface);
    img_screenSurface = NULL;

    // Destroy main window
    SDL_DestroyWindow(main_window);
    main_window = NULL;

    // Quit SDL subsystem
    SDL_Quit();
}
