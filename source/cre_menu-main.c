#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <stdio.h>

static int menu_visible = 0;
static float w_quit = 80.0f;
static float h_quit = 40.0f;

static void draw_button_menu(SDL_Renderer *renderer, float x, float y, float w, float h) {   
    SDL_FRect button_rect = {x, y, w, h}; 
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &button_rect);
}

static void draw_menu(SDL_Renderer *renderer, float w, float h, float pad, int linhas, int colunas) {
    float k = 8;
    float x_menu = w/k;
    float y_menu = h/k;
    float w_menu = w*(8 - 2)/k;
    float h_menu = h*(8 - 2)/k;
    float button_w = (w_menu - 3*pad - w_quit)/colunas;
    float button_h = (h_menu - 5*pad - h_quit)/linhas;
    SDL_FRect menu_rect = {x_menu, y_menu, w_menu, h_menu}; // x, y, w, h
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 200);
    SDL_RenderFillRect(renderer, &menu_rect);
    for (int j = 1; j <= linhas; j++) {
        for (int i = 1; i <= colunas; i++) {
            float x_button = x_menu + (float)i*pad + (float)(i-1)*button_w;
            float y_button = y_menu + (float)j*pad + (float)(j-1)*button_h;
            draw_button_menu(renderer, x_button, y_button, button_w, button_h);
        }
    }
    float x_quit = w - x_menu - w_quit;
    float y_quit = h - y_menu - h_quit;
    draw_button_menu(renderer, x_quit, y_quit, w_quit, h_quit);
}

void draw_hud(SDL_Renderer *renderer, float w, float h, float pad, int linhas, int colunas) {
    if (menu_visible) {
        draw_menu(renderer, w, h, pad, linhas, colunas);
    }
}

void handle_menu_event() {
    // Toggle menu visibility
    menu_visible = !menu_visible;
}

int get_menu_visibility() {
    return menu_visible;
}
