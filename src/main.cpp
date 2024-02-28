#include "ui.h"
#include <iostream>
#include <SDL.h>

SDL_Window* main_window = NULL;
SDL_Surface* main_screenSurface = NULL;
SDL_Surface* img_screenSurface = NULL;

int main(int argc, char* args[]) {
    // start SDL and create main window
    if(!ui_init())
        std::cout << "Failed to initialize!" << std::endl;
    else {
        // Load media
        if(!ui_loadMedia())
            std::cout << "Failed to load media!" << std::endl;
        else {
            // Apply the image
            SDL_BlitSurface(img_screenSurface, NULL, main_screenSurface, NULL);

            // Update the surface
            SDL_UpdateWindowSurface(main_window);
        }

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

    // Free resources and close SDL
    ui_close();

    return 0;
}
