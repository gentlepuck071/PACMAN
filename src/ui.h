#ifndef UI_ELEMENTS
#define UI_ELEMENTS

#include <SDL.h>
#include <string>

const std::string imgPath = "res/amongus.bmp";
const int MAIN_WINDOW_WIDTH = 600;
const int MAIN_WINDOW_HEIGHT = 600;

extern SDL_Window* main_window;
extern SDL_Surface* main_screenSurface;
extern SDL_Surface* img_screenSurface;

bool ui_init();
bool ui_loadMedia();
void ui_close();

#endif
