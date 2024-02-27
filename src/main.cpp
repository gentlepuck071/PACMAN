#include <SDL.h>

// Constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SQUARE_SIZE = 50;

// Function to handle events
void handleEvents(SDL_Event& e, bool& quit, int& posX, int& posY);

int main(int argc, char* args[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Moving Square", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Initial position of the square
    int posX = SCREEN_WIDTH / 2 - SQUARE_SIZE / 2;
    int posY = SCREEN_HEIGHT / 2 - SQUARE_SIZE / 2;

    // Game loop
    bool quit = false;
    SDL_Event e;

    while (!quit) {
        // Event handling
        handleEvents(e, quit, posX, posY);

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw the moving square
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_Rect squareRect = { posX, posY, SQUARE_SIZE, SQUARE_SIZE };
        SDL_RenderFillRect(renderer, &squareRect);

        // Update the screen
        SDL_RenderPresent(renderer);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void handleEvents(SDL_Event& e, bool& quit, int& posX, int& posY) {
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            quit = true;
        } else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_UP:
                    posY -= 10;
                    break;
                case SDLK_DOWN:
                    posY += 10;
                    break;
                case SDLK_LEFT:
                    posX -= 10;
                    break;
                case SDLK_RIGHT:
                    posX += 10;
                    break;
            }
        }
    }
}

