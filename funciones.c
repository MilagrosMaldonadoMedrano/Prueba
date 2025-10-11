#include<stdio.h>
#include "funciones.h"
#include <string.h>

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
