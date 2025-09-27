#ifndef SIMON_H
#define SIMON_H

#define SCREEN_W 1366
#define SCREEN_H 768

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL_ttf.h>

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#include "Vector.h"
#include "sonido.h"
#include "Dibujo.h"
#include "Vector.h"
#include "Funciones.h"

typedef struct {
Vector secuencia; //guarda la secuencia de botones
int tam; // longitud actual de la secuencia
int indiceJugador; //en que paso esta el jugador
int enJuego; //flag de estado
}Simon;

typedef struct{
char nombre[10]; //nombre del jugador
int nivel; // nivel actual o maximo de rondas que supero
int puntaje; //puntos acumulados
}Jugador;


//Juego basico
void pulsarSectorLuz(SDL_Renderer *renderer, const int m[][ORDEN], int orden);
void simon1(SDL_Renderer* renderer,const int simon[][ORDEN],int cantidad);


void simon(SDL_Renderer* renderer, const int simon[][ORDEN], int cantidad, Jugador* jugador);
Simon* simonCrear(int cantidad);
void mostrarSecuencia(Simon* juego, SDL_Renderer* renderer, const int simon[][ORDEN], int iniX, int iniY, Sonido** notas,float duracion,int tiempoDelay);
int procesarEntrada(Simon* juego, SDL_Event* e, const int simon[][ORDEN], int iniX, int iniY, SDL_Renderer* renderer, Sonido** notas,int cantidad,float duracion);


#endif // SIMON_H
