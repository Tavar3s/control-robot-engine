#ifndef CRE_MENU_MAIN_H
#define CRE_MENU_MAIN_H

void draw_hud(SDL_Renderer *renderer, float w, float h, float pad, int linhas, int colunas);
void handle_menu_event();
int get_menu_visibility();

#endif