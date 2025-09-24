#ifndef DIBUJO_H
#define DIBUJO_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#define TAM_PIXEL 12
#define ORDEN 60
#define ORDENMENU 11
//SIMON 8



#define Z 0 //AZUL
#define A 1 //AMARILLO
#define R 2 //ROJO
#define V 3 //VERDE
#define C 4 //CELESTE
#define O 5 //NARANJA
#define W 6 //VIOLETA
#define P 7//Rosa
#define B 8  //BLANCO
#define T 9  //TRANSPARENTE
#define G 10  //GRIS
#define N 11 //NEGRO
//COLORES FONDO
#define V0 12
#define V1 13
#define V2 14
#define V3 15


void dibujar(SDL_Renderer *renderer, const int m[][ORDEN], int filas, int columnas, int origenX, int origenY);
void imprimirDeteccion(int deteccion);
void iluminarZona(const int zona,const int m[][ORDEN],const int orden,int origx,int origy,SDL_Renderer *renderer,int zonaMod);
void dibujarEnMenu(SDL_Renderer *renderer, const int m[][ORDENMENU], int filas, int columnas, int origenX, int origenY,int escalar);




#endif // DIBUJO_H
