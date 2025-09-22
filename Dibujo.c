#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include "funciones.h"

SDL_Color colores[] =
{
    {0, 0, 255, 255}, //AZUL[0]
    {255, 255, 0,   255}, // Y[1] - Amarillo
    {255,   0,  0,  255}, // R[2] - Rojo
    {0,   150, 60,  255}, // V[3] - Verde
    {255, 255, 255, 255}, // B[4] - Blanco
    {138, 149, 151, 255}, // T[5] - Transparente AL FONDO
    {138, 149, 151, 255}, //G[6]
    {0,   0,   0,   255}, // N[7] - Negro
    {255, 105, 97, 255}   //ROJO CLARO[8]

};



void dibujar(SDL_Renderer *renderer, const int m[][ORDEN], int filas, int columnas, int origenX, int origenY)
{
    int indiceColor;
    for (int y = 0; y < filas; y++)
    {
        for (int x = 0; x < columnas; x++)
        {
            indiceColor=m[y][x];

            SDL_Color color = colores[indiceColor];

            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);

            SDL_Rect pixel = {
                origenX + x * TAM_PIXEL,
                origenY + y * TAM_PIXEL,
                TAM_PIXEL,
                TAM_PIXEL
            };

            SDL_RenderFillRect(renderer, &pixel);
        }
    }

    SDL_RenderPresent(renderer);
}


void iluminarZona(int zona,const int m[][ORDEN],int orden,int origx,int origy,SDL_Renderer *renderer,int zonaMod)
{
    int indiceColor;

    for(int y=0;y<orden;y++)
    {
        for(int x=0;x<orden;x++)
        {
            if(m[y][x]==zona)
                indiceColor=zonaMod;
            else
                indiceColor=m[y][x];


            SDL_Color col=colores[indiceColor];
            SDL_SetRenderDrawColor(renderer,col.r,col.g,col.b,255);

            SDL_Rect pixel={origx+x*TAM_PIXEL,origy+y*TAM_PIXEL,TAM_PIXEL,TAM_PIXEL};

            SDL_RenderFillRect(renderer,&pixel);
        }

    }
    SDL_RenderPresent(renderer);
}




