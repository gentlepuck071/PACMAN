#include "ui.h"
#include <iostream>
#include <SDL.h>

int main(int argc, char* args[]) {
    UserInterface mainUI;

    if(mainUI.init()) {
        if(mainUI.loadMedia())
            mainUI.gameLoop();
    }

    mainUI.close();

    return 0;
}
