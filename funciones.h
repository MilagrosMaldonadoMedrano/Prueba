#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include<time.h>
//#include<SDL_ttf>
#define TAM 30
#define TAM_PIXEL 30
#define ORDEN 21
#define A 1
#define T 5
#define N 7

#define B 4
#define R 2

#define V 3
#define G 6
#define Z 0
#define RC 8

SDL_Color colores[] =
{
    {0, 0, 255, 255}, //AZUL[0]
    {255, 255, 0,   255}, // Y[1] - Amarillo
    {255,   0,  0,  255}, // R[2] - Rojo
    {0,   150, 60,  255}, // V[3] - Verde
    {255, 255, 255, 255}, // B[4] - Blanco

    {138, 149, 151, 255},  // T[5] - Transparente AL FONDO
    {138, 149, 151, 255},  //G[6]
    {0,   0,   0,   255}, // N[7] - Negro
    {255, 105, 97, 255} //ROJO CLARO[8]

};

const int simon[ORDEN][ORDEN] = {
    {T,T,T,T,T,T,T,N,N,N,N,N,N,N,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,N,V,V,V,N,R,R,R,N,T,T,T,T,T,T},
    {T,T,T,T,T,N,V,V,V,V,N,R,R,R,R,N,T,T,T,T,T},
    {T,T,T,T,N,V,V,V,V,V,N,R,R,R,R,R,N,T,T,T,T},
    {T,T,T,N,V,V,V,V,V,V,N,R,R,R,R,R,R,N,T,T,T},
    {T,T,N,V,V,V,V,V,V,V,N,R,R,R,R,R,R,R,N,T,T},
    {T,N,V,V,V,V,V,V,V,V,N,R,R,R,R,R,R,R,R,N,T},
    {N,V,V,V,V,V,V,V,V,V,N,R,R,R,R,R,R,R,R,R,N},
    {N,V,V,V,V,V,V,V,V,N,N,N,R,R,R,R,R,R,R,R,N},
    {N,V,V,V,V,V,V,V,N,N,N,N,N,R,R,R,R,R,R,R,N},
    {N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N},
    {N,A,A,A,A,A,A,A,N,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,N},
    {N,A,A,A,A,A,A,A,A,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,N},
    {N,A,A,A,A,A,A,A,A,A,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,N},
    {T,N,A,A,A,A,A,A,A,A,N,Z,Z,Z,Z,Z,Z,Z,Z,N,T},
    {T,T,N,A,A,A,A,A,A,A,N,Z,Z,Z,Z,Z,Z,Z,N,T,T},
    {T,T,T,N,A,A,A,A,A,A,N,Z,Z,Z,Z,Z,Z,N,T,T,T},
    {T,T,T,T,N,A,A,A,A,A,N,Z,Z,Z,Z,Z,N,T,T,T,T},
    {T,T,T,T,T,N,A,A,A,A,N,Z,Z,Z,Z,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,A,A,A,N,Z,Z,Z,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,N,N,N,N,N,N,T,T,T,T,T,T,T}
};

void dibujar(SDL_Renderer *renderer, const int m[][ORDEN], int filas, int columnas, int origenX, int origenY);
int detectarClic(int x, int y,const int m[][ORDEN],int orden,int xMat,int yMat);
void imprimirDeteccion(int deteccion);
void iluminarZona(const int zona,const int m[][ORDEN],const int orden,int origx,int origy,SDL_Color colores[],SDL_Renderer *renderer,int zonaMod);
void pulsarSectorLuz(SDL_Renderer *renderer, const int m[][ORDEN], int orden);


#endif // FUNCIONES_H_INCLUDED
