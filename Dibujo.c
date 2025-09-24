#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include "funciones.h"

SDL_Color colores[] =
{
    {  0,   0, 255, 255}, //AZUL[0]
    {255, 255,   0, 255}, // Y[1] - Amarillo
    {204,  24,  24, 255}, // R[2] - Rojo
    {  0, 150,  60, 255}, // V[3] - Verde
    { 63, 133, 212, 255}, //Celeste[4]
    {255, 128,   0, 255}, //Naranja[5]
    {156,  55, 176, 255}, //Violeta[6]
    {219,  37, 133, 255}, //Rosa[7]
    {255, 255, 255, 255}, // B[8] - Blanco
    {138, 149, 151, 255}, // T[9] - Transparente AL FONDO
    {138, 149, 151, 255}, //G[10]
    {  0,   0,   0, 255}, // N[11] - Negro

    //COLORES MENU
    { 36,  9,   66, 255}, //VIOLETA1[12]
    { 52,  12,  97, 255}, //VIOLETA2[13]
    { 86,  43, 135, 255}, //VIOLETA2[14]
    {111,  62, 163, 255}  //VIOLETA3[15]
};

/*SDL_Color coloresMenu[]=
{
    {255, 74, 12, 255}, //VIOLETA1[0]
    {255, 69, 21, 255}, //VIOLETA2[1]
    {255, 69, 21, 255}, //VIOLETA2[2]
    {70, 30, 130, 255}, //VIOLETA3[3]
    {95, 55, 158, 255}  //VIOLERA4[4]

};*/





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
            SDL_SetRenderDrawColor(renderer,col.r,col.g,col.b,150);

            SDL_Rect pixel={origx+x*TAM_PIXEL,origy+y*TAM_PIXEL,TAM_PIXEL,TAM_PIXEL};

            SDL_RenderFillRect(renderer,&pixel);
        }

    }
    SDL_RenderPresent(renderer);
}

void dibujarEnMenu(SDL_Renderer *renderer, const int m[][ORDENMENU], int filas, int columnas, int origenX, int origenY, int escalar)
{
    int indiceColor;
    srand(time(0));
    //int escalar=(rand() % 3)+1;
    escalar=escalar*2;


    for (int y = 0; y < filas; y++)
    {
        for (int x = 0; x < columnas; x++)
        {
            indiceColor=m[y][x];

            SDL_Color color = colores[indiceColor];

            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);

            SDL_Rect pixel = {
                (origenX-(ORDENMENU*escalar)/2) + x * escalar,
                (origenY-(ORDENMENU*escalar)/2) + y * escalar,
                escalar,
                escalar
            };

            SDL_RenderFillRect(renderer, &pixel);
        }
    }

    SDL_RenderPresent(renderer);
}

void dibujar8(SDL_Renderer *renderer, const int m[][60], int filas, int columnas, int origenX, int origenY)
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


