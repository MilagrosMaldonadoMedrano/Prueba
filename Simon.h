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

#define PATH_FNT_ARIAL "fnt/arial.ttf"
#define TAM_FNT_MENU 22

typedef struct {
Vector secuencia; //guarda la secuencia de botones
int tam; // longitud actual de la secuencia
int indiceJugador; //en que paso esta el jugador
int enJuego; //flag de estado
bool cheat;
}Simon;
typedef struct {
    char nombre[10];
    int nivel;
    int puntaje;
    int colores;
    int modo;
    int velocidad;
    bool cheat;
} Jugador;

//Juego basico
void pulsarSectorLuz(SDL_Renderer *renderer, const int m[][ORDEN], int orden);
void simon1(SDL_Renderer* renderer,const int simon[][ORDEN],int cantidad);

void simon(SDL_Renderer* renderer, const int simon[][ORDEN], Jugador* jugador);
Simon* simonCrear(int cantidad);
void mostrarSecuencia(Simon* juego, SDL_Renderer* renderer, const int simon[][ORDEN], int iniX, int iniY, Sonido** notas,float duracion,int tiempoDelay);
int procesarEntrada(Simon* juego, SDL_Event* e, const int simon[][ORDEN], int iniX, int iniY, SDL_Renderer* renderer, Sonido** notas,int cantidad,float duracion);
void rotarSimon(int simon[][ORDEN],int simonAux[][ORDEN]);
void DeterminarJuego(Jugador * jug, SDL_Renderer *renderer);
void cargarSimon(const int simon[][ORDEN],int simonRotable[][ORDEN]);
void CopiarSimon(int origen[][ORDEN], int destino[][ORDEN]);

void mozart(SDL_Renderer* renderer, const int simon[][ORDEN], int cantidad, Jugador* jugador,int simonRotable[][ORDEN],char* nombreArchivo);
void desafio(SDL_Renderer* renderer, const int simon[][ORDEN], int cantidad, Jugador* jugador,const char* nombreArch);

#endif // SIMON_H
