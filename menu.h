#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include "Simon.h"

#define SCREEN_W 1366
#define SCREEN_H 768
#define MAX_LENGTH 30

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

typedef struct
{
    SDL_Rect rect;//dibuja un rectangulo
    char texto[31];
    SDL_Color color;
    int activo;
} Input;

typedef struct
{
    char usuario[31];
    int velocidad;
    int modo;
    int colores;
} Configuracion;

void boton_carga(Boton* b, int x, int y, int w, int h, char* texto,
                 SDL_Color normal, SDL_Color encima, SDL_Color presionado);
void boton_render(SDL_Renderer* renderer, Boton* b, TTF_Font* fuente);
int boton_manejo_evento(Boton* b, SDL_Event* e);
void botones_menu(Boton* botones, int cantidad, int screen_w, int screen_h);
void Log_in(Configuracion *usuario, SDL_Renderer* renderer, TTF_Font* fuente);
void input_carga(Input*, int x, int y, int w, int h, char* texto, SDL_Color normal);
void input_render(SDL_Renderer* renderer, Input* i, TTF_Font* fuente);
int input_manejo_evento(Input *i, SDL_Event *e);
void EscribirPalabra(SDL_Event *evento, Input * campo);
bool CorroborarUsuario(char* usu, Configuracion *usuario);
void configuracionJugador(Configuracion *usu, Jugador *jug);
void GuardarModo(Jugador * jugador);


#endif // MENU_H_INCLUDED

