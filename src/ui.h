#ifndef UI_CLASS
#define UI_CLASS

#include <SDL.h>
#include <string>

class UserInterface {
    public:
        bool init();
        bool loadMedia();
        void close();
        int gameLoop();

    private:
        int MAIN_WINDOW_WIDTH = 600;
        int MAIN_WINDOW_HEIGHT = 800;
        SDL_Window* mainWindow = NULL;
        SDL_Surface* mainScrSurface = NULL;
        SDL_Surface* backgroundSurface = NULL;
        std::string backgroundImgPath = "res/amongus.bmp";
};

#endif
