#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <SDL2/SDL.h>
#include <SDL_ttf.h>

typedef struct
{
    SDL_Rect rect;//dibuja un rectangulo
    char* texto;
    SDL_Color color;
    SDL_Color encima_color;//cuando el cursor esta encima del boton
    SDL_Color presionado_color;
    int encima;
    int presionado;
} Boton;



void boton_carga(Boton* b, int x, int y, int w, int h, char* texto,
                 SDL_Color normal, SDL_Color encima, SDL_Color presionado);
void boton_render(SDL_Renderer* renderer, Boton* b, TTF_Font* fuente);
int boton_manejo_evento(Boton* b, SDL_Event* e);
void botones_menu(Boton* botones, int cantidad, int screen_w, int screen_h);


#endif // MENU_H_INCLUDED
