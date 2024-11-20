#ifndef APP
#define APP

#include <SDL2/SDL.h>

class App {
public:
    enum WindowMode {
        FULLSCREEN,
        FULLSCREEN_BORDERLESS,
        WINDOWED
    };

    bool Init(const char* title, int w, int h, WindowMode mode);
    void Quit();

    void Render();

    int GetWindowWidth();
    int GetWindowHeight();

    WindowMode GetWindowMode();
    void SetWindowMode(WindowMode mode);

    App();
    ~App();

private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

    int m_windowWidth;
    int m_windowHeight;
    WindowMode m_windowMode;
};


#endif