#define SDL_MAIN_HANDLED

#include <iostream>
#include "app/app.h"

int main(int argc, char* argv[])
{
    SDL_SetMainReady();
    
    App app;

    if (!app.Init("Quantum Shooter", 640, 480, App::WindowMode::WINDOWED)) {
        return -1;
    }

    while (!SDL_QuitRequested()) {
        app.Render();
    }

    app.Quit();
    return 0;
}
