#include <SDL.h>
#include <iostream>

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(void) {
    // Window
    SDL_Window* window = NULL;

    // Surface contained by the window
    SDL_Surface* screen_surface = NULL;

    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cout << "Could not initialize SLD! SLD_Error: " << SDL_GetError() << std::endl;
    else {
        // Create window
        window = SDL_CreateWindow("My Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window == NULL)
            std::cout << "Could not create window!" << SDL_GetError() << std::endl;
        else {
            // Get window surface
            screen_surface = SDL_GetWindowSurface(window);
            // Fill surface with white
            SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0xFF, 0xFF, 0xFF));
            // Update surface
            SDL_UpdateWindowSurface(window);

            // Window loop
            SDL_Event e;
            bool quit = false;
            while(!quit) {
                while(SDL_PollEvent(&e)) {
                    if(e.type == SDL_QUIT)
                        quit = true;
                }
            }
        }
    }

    // Destroy window
    SDL_DestroyWindow(window);
    // Quit SDL subsystem
    SDL_Quit();

    return 0;
}
