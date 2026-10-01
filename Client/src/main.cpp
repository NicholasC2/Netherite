#include <SDL3/SDL.h>
#include <glad/gl.h>
#include <ft2build.h>
#include FT_FREETYPE_H

#include <glm/glm.hpp>

#include <Nether/Nether.hpp>

int main() {
    if(!Nether::Init()) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "libNether Error!", "Failed to initialize!", nullptr);

        return -1;
    }

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL Init Error!", SDL_GetError(), nullptr);

        return -1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_Window* window = SDL_CreateWindow("Netherite Client", 960, 640, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    if (!window) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL Window Creation Error!", SDL_GetError(), nullptr);

        SDL_Quit();
        return -1;
    }

    SDL_SetWindowAspectRatio(window, 16.0f / 9.0f, 16.0f / 9.0f);

    SDL_GLContext glContext = SDL_GL_CreateContext(window);

    if (!glContext) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "OpenGL Context Creation Error!", SDL_GetError(), nullptr);

        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    if (!gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress)) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Failed to load OpenGL", "", nullptr);
        
        return -1;
    }

    FT_Library ft;

    if (FT_Init_FreeType(&ft)) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Failed to initialize FreeType", "", nullptr);

        return -1;
    }

    bool running = true;

    Uint64 lastTime = SDL_GetPerformanceCounter();

    while (running) {
        Uint64 currentTime = SDL_GetPerformanceCounter();

        float deltaTime =
            (float)(currentTime - lastTime) /
            (float)SDL_GetPerformanceFrequency();

        lastTime = currentTime;

        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DestroyContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
