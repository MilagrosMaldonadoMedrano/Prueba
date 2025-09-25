#ifndef SIMON_H
#define SIMON_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include<time.h>



//Juego basico
void pulsarSectorLuz(SDL_Renderer *renderer, const int m[][ORDEN], int orden);
void simon(SDL_Renderer* renderer,const int simon[][ORDEN],int cantidad);


#endif // SIMON_H
