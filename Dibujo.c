#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include "funciones.h"

const SDL_Color colores[] =
{
    {  0,   0, 255, 255}, //AZUL[0]
    {255, 255,   0, 255}, // Y[1] - Amarillo
    {204,  24,  24, 255}, // R[2] - Rojo
    {  0, 150,  60, 255}, // V[3] - Verde
    {255, 128,   0, 255}, //Naranja[4]
    {156,  55, 176, 255}, //Violeta[5]
    { 63, 133, 212, 255}, //Celeste[6]


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


void imprimirDeteccion(int deteccion)
{
    if(deteccion==-1 || deteccion==T)
        printf("Se ha realizado un clic fuera del Simon.\n");
    if(deteccion==R)
        puts("Se ha realizado un clic en el color rojo.\n");
    if(deteccion==V)
        puts("Se ha realizado un clic en el color verde.\n");
    if(deteccion==Z)
        puts("Se ha realizado un clic en el color azul.\n");
    if(deteccion==A)
        puts("Se ha realizado un clic en el color amarillo.\n");
    if(deteccion==N )
        puts("Se ha realizado un clic en un borde del Simon.\n");
}

int detectarClic(int x, int y, const int m[][ORDEN],int orden,int xMat,int yMat)
{
    int deteccion=-1;

    //x e y son las coordenadas del clic realizado en la ventana
    //xMat e yMat son las coordenadas donde inicia la matriz en pixeles a dibujarse en la ventanita
    //orden*TAM_PIXEL es el orden total de la matriz en pixeles

    //veo que el clic corresponda dentro de la matriz en pixeles
    if(x>=xMat && x<=xMat+orden*TAM_PIXEL && (y>=yMat && y<=yMat+orden*TAM_PIXEL))
    {
        //traduzco las coordenadas en pixeles a posiciones de la matriz
        int fila= (y-yMat)/TAM_PIXEL;
        int columna=(x-xMat)/TAM_PIXEL;

        //if(fila >= 0 && fila < orden && columna >= 0 && columna < orden)
        deteccion = m[fila][columna];
    }


    return deteccion;
}

