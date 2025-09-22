#ifndef DIBUJO_H
#define DIBUJO_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#define TAM_PIXEL 30
#define ORDEN 21
#define Z 0
#define A 1
#define R 2
#define V 3
#define B 4
#define T 5
#define G 6
#define N 7
#define RC 8


void dibujar(SDL_Renderer *renderer, const int m[][ORDEN], int filas, int columnas, int origenX, int origenY);
void imprimirDeteccion(int deteccion);
void iluminarZona(const int zona,const int m[][ORDEN],const int orden,int origx,int origy,SDL_Renderer *renderer,int zonaMod);






#endif // DIBUJO_H
