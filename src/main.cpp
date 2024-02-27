#include <SDL.h>
#include <iostream>

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 800

int main(void) {
    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Could not initialize SDL! SLD_Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    std::cout << "SLD initialized succesfully!" << std::endl;

    // Create main window
    SDL_Window* main_window = SDL_CreateWindow("Main Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if(!main_window) {
        std::cout << "Could not create main window! SLD_Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    // Create secondary window
    SDL_Window* sec_window = SDL_CreateWindow("Secondary Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if(!sec_window) {
        std::cout << "Could not create secondary window! SLD_Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    
    // Create main renderer
    SDL_Renderer* main_renderer = SDL_CreateRenderer(main_window, -1, SDL_RENDERER_ACCELERATED);
    if(!main_renderer) {
        std::cout << "Could not create main renderer! SLD_Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    // Create secondary renderer
    SDL_Renderer* sec_renderer = SDL_CreateRenderer(sec_window, -1, SDL_RENDERER_ACCELERATED);
    if(!sec_renderer) {
        std::cout << "Could not create secondary renderer! SLD_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    bool quit = false;
    SDL_Event e;
    while(!quit) {
        while(SDL_PollEvent(&e) != 0) {
            if(e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Main Window
        SDL_SetRenderDrawColor(main_renderer, 0, 0, 0, 255);
        SDL_RenderClear(main_renderer);
        SDL_RenderPresent(main_renderer);
        
        // Secondary Window
        SDL_SetRenderDrawColor(sec_renderer, 255, 0, 0, 255);
        SDL_RenderClear(sec_renderer);
        SDL_RenderPresent(sec_renderer);
    }

    // Cleanup
    SDL_DestroyRenderer(main_renderer);
    SDL_DestroyWindow(main_window);
    SDL_DestroyWindow(sec_window);
    SDL_DestroyRenderer(sec_renderer);
    SDL_Quit();

    return 0;
}
