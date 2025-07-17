#define SDL_MAIN_USE_CALLBACKS 1  
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "../include/cre_menu-main.h"
#include <stdio.h>

#define FONT_PATH "C:/Users/Usuario/c-and-cpp-college/control-robot-engine/font/courierprimeregular.ttf"

/*gcc .\test\run-tests.c .\source\cre_menu-main.c -o .\output\teste.exe -I "C:\SDL\x86_64-w64-mingw32\include" -I "C:\SDL_ttf\x86_64-w64-mingw32\include" -L "C:\SDL\x86_64-w64-mingw32\lib" -L "C:\SDL_ttf\x86_64-w64-mingw32\lib" -lSDL3 -lSDL3_ttf*/

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
static TTF_Font *font_app;
static SDL_Texture *texture;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
    SDL_SetAppMetadata("Run test app", "1.0", "com.run.test-app");

    if (!SDL_Init(SDL_INIT_VIDEO) && !TTF_Init()) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("run/test/app", 640, 480, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    font_app = TTF_OpenFont("font/courierprimeregular.ttf", 36);
    if (!font_app) {
        SDL_Log("Couldn't load font: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_Surface *surface = TTF_RenderText_Blended(font_app, "Hello, World!", 0, (SDL_Color){255, 255, 255, 255});
    if (!surface) {
        SDL_Log("Couldn't render text: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);
    surface = NULL;

    if (!texture) {
        SDL_Log("Couldn't create texture from surface: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }
    
    if (event->type == SDL_EVENT_KEY_UP) {
        SDL_Keycode sym = event->key.key;
        if (sym == SDLK_E) { 
            handle_menu_event(); // Toggle rectangle visibility when E is released
        }
        if (sym == SDLK_ESCAPE) {
            return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
        }
    }

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
    SDL_RenderClear(renderer);

    // Draw rectangle if flag is set
    if (get_menu_visibility()) {
        draw_hud(renderer, 640, 480, 20, 5, 2); // Draw the HUD/menu overlay
    }

    SDL_RenderTexture(renderer, texture, NULL, NULL);

    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    if (font_app) {
        TTF_CloseFont(font_app);
        font_app = NULL;
    }

    if (texture) {
        SDL_DestroyTexture(texture);
        texture = NULL;
    }
}