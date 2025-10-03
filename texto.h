#ifndef TEXTO_H_INCLUDED
#define TEXTO_H_INCLUDED

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL_ttf.h>
#include "Simon.h"

int textIni();
TTF_Font* cargarFnt(const char* path, int tamFnt);
void mostrarTexto(SDL_Renderer* renderer, TTF_Font* fnt, const char* texto, int x, int y, SDL_Color color);
void mostrarEstadisticaSimon(SDL_Renderer* renderer, TTF_Font* fnt, Jugador* jugador, int nivelSimon);
void ingresarNombre(SDL_Renderer* renderer, TTF_Font* fnt, Jugador* jugador);


#endif // TEXTO_H_INCLUDED
