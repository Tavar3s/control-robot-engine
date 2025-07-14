#include <SDL3/SDL.h>
#include <stdio.h>

static int menu_visible = 0;

static void draw_menu(SDL_Renderer *renderer, float w, float h) {
    SDL_FRect menu_rect = {w/8, h/8, w*(8 - 2)/8, h*(8 - 2)/8};
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_RenderFillRect(renderer, &menu_rect);
}

void draw_hud(SDL_Renderer *renderer, float w, float h) {
    if (menu_visible) {
        draw_menu(renderer, w, h);
    }
}

void handle_menu_event() {
    // Toggle menu visibility
    menu_visible = !menu_visible;
}

int get_menu_visibility() {
    return menu_visible;
}
