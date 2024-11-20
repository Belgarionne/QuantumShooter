#include <iostream>
#include "app.h"

App::App() : m_pWindow(nullptr), m_pRenderer(nullptr), m_windowWidth(0), m_windowHeight(0), m_windowMode(WindowMode::WINDOWED) {}
App::~App() {}

bool App::Init(const char* title, int w, int h, WindowMode mode) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        std::cout << "ERROR: Failed to init SDL subsystems." << std::endl;
        Quit();
        return false;
    }

    Uint32 windowModeFlag = 0;
    switch (mode)
    {
        case FULLSCREEN:
            windowModeFlag = SDL_WINDOW_FULLSCREEN;
            break;
        case FULLSCREEN_BORDERLESS:
            windowModeFlag = SDL_WINDOW_FULLSCREEN_DESKTOP;
            break;
        case WINDOWED:
            windowModeFlag = 0;
            break;
    }

    m_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, windowModeFlag | SDL_WINDOW_ALLOW_HIGHDPI);
    if (m_pWindow == nullptr) {
        std::cout << "ERROR: Failed to create an SDL window." << std::endl;
        Quit();
        return false;
    }

    m_windowWidth = w;
    m_windowHeight = h;
    m_windowMode = mode;

    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
    if (m_pRenderer == nullptr) {
        std::cout << "ERROR: Failed to create an SDL renderer." << std::endl;
        Quit();
        return false;
    }

    std::cout << "Successfully finished initializing application." << std::endl;
    return true;
}

void App::Quit() {
    if (m_pWindow != nullptr) {
        SDL_DestroyWindow(m_pWindow);
    }
    if (m_pRenderer != nullptr) {
        SDL_DestroyRenderer(m_pRenderer);
    }

    SDL_Quit();
}

void App::Render() {
    SDL_SetRenderDrawColor(m_pRenderer, 46, 101, 255, 255);
    SDL_RenderClear(m_pRenderer);
    SDL_RenderPresent(m_pRenderer);
}

int App::GetWindowWidth() { return m_windowWidth; }
int App::GetWindowHeight() { return m_windowHeight; }

App::WindowMode App::GetWindowMode() { return m_windowMode; }
void App::SetWindowMode(WindowMode mode) {
    Uint32 windowModeFlag = 0;
    switch (mode)
    {
        case FULLSCREEN:
            windowModeFlag = SDL_WINDOW_FULLSCREEN;
            break;
        case FULLSCREEN_BORDERLESS:
            windowModeFlag = SDL_WINDOW_FULLSCREEN_DESKTOP;
            break;
        case WINDOWED:
            windowModeFlag = 0;
            break;
    }

    SDL_SetWindowFullscreen(m_pWindow, windowModeFlag);
}
