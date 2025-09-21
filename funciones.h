#ifndef FUNCIONES_H
#define FUNCIONES_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "Dibujo.h"


void imprimirDeteccion(int deteccion);
int detectarClic(int x, int y,const int m[][ORDEN],int orden,int xMat,int yMat);


#endif // FUNCIONES_H
