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

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO); // inicia los subsistemas de audio y video
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Chunk *sonido_click;
    // Cargar el archivo de sonido
    sonido_click = Mix_LoadWAV("C:/Users/botta/Documents/GitHub/Prueba/snd/do.wav");

    SDL_Window *ventana  = SDL_CreateWindow("Ventanita",
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           1000,
                                           1000,
                                           SDL_WINDOW_SHOWN);//declara la ventana del juego


    SDL_Renderer *renderer = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED); // crea el render
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); // establece su opacidad



    //FUNCION JUEGO BASICO
    //pulsarSectorLuz(renderer,simon,ORDEN);

    SDL_Event evento;
    int inicioX=(1000/2)-(ORDEN*TAM_PIXEL/2);
    int inicioY=(1000/2)-(ORDEN*TAM_PIXEL/2);
    int ejecutando=1;


    //Preparo el color del fondo
    SDL_SetRenderDrawColor(renderer, 138, 149, 151, 255); //Color turquesa
    SDL_RenderClear(renderer);    // Limpia toda la pantalla con ese color
    SDL_RenderPresent(renderer); //actualiza la ventana

    int x, y, deteccion, sector;

    dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
    SDL_Delay(300);
    srand(time(0));
    sector=rand() % 4;
    //iluminarZona(sector,simon,ORDEN,inicioX,inicioY,colores,renderer,B);


    //int registroClics[15];
    int registroDetecciones[15];
    registroDetecciones[0]=sector;

    int contador=1, contAux, acierto=1;

    while(ejecutando)
    {
        SDL_Delay(150);
        dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);

        //recorre el registro de detecciones iluminando cada zona
        for(int i = 0; i < contador; i++)
        {
            SDL_Delay(300);
            iluminarZona(registroDetecciones[i],simon,ORDEN,inicioX,inicioY,colores,renderer,B);
            Mix_PlayChannel(-1, sonido_click, 0);
            SDL_Delay(300 -(i+1));
            dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
        }

        contAux=0;
        //aca analizo cada secuencia de clics que ejecuta el usuario
        while(contAux<contador && acierto==1)
        {
            while(SDL_PollEvent(&evento))//detecta los eventos
            {
                //si el evento es especificamente el clic izq lo analiza
                if((evento.type == SDL_MOUSEBUTTONDOWN) && (evento.button.button == SDL_BUTTON_LEFT))
                {
                    x=evento.button.x;
                    y=evento.button.y;
                    deteccion=detectarClic(x,y,simon,ORDEN,inicioX,inicioY); //veo en el sector en el que se ejecutó el clic
                    iluminarZona(deteccion,simon,ORDEN,inicioX,inicioY,colores,renderer,N);
                    Mix_PlayChannel(-1, sonido_click, 0);
                    SDL_Delay(150);
                    dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
                    if(deteccion != -1)
                    {
                        //si el sector en el que se ejecutó el clic es igual a la posisicon conAux del vector que contiene toda la secuencia aumenta el contAux, porque es un ACIERTO
                        if(deteccion==registroDetecciones[contAux])
                        {
                            contAux++;
                        }
                        else //Caso contrario el clic fue en otro sector
                        {
                            printf("Ha perdido!\n");
                            acierto=0;
                            ejecutando=0;
                        }
                    }
                }
            }
        }

        if(acierto)
        {
            printf("Ha acertado.\n");
            //genero la nueva luz
            contador++;
            registroDetecciones[contador]=rand() % 4;
        }
    }



    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    SDL_Quit();
    return 0;
}

void pulsarSectorLuz(SDL_Renderer *renderer, const int m[][ORDEN], int orden)
{
    SDL_Event evento;
    int inicioX=(1000/2)-(orden*TAM_PIXEL/2);
    int inicioY=(1000/2)-(orden*TAM_PIXEL/2);
    int ejecutando=1;

    SDL_SetRenderDrawColor(renderer, 138, 149, 151, 255); //Color turquesa
    SDL_RenderClear(renderer);    // Limpia toda la pantalla con ese color
    SDL_RenderPresent(renderer); //actualiza la ventana


    int x;
    int y;
    int deteccion;
    int salir=1;
    int sector;


    dibujar(renderer,simon,orden,orden,inicioX,inicioY);
    SDL_Delay(300);
    srand(time(0));
    sector=rand() % 4;
    iluminarZona(sector,simon,orden,inicioX,inicioY,colores,renderer,B);


    while(ejecutando)
    {
        SDL_Delay(150);
        dibujar(renderer,simon,orden,orden,inicioX,inicioY);


        while(SDL_PollEvent(&evento) && salir==1)
        {

            if((evento.type == SDL_MOUSEBUTTONDOWN) && (evento.button.button == SDL_BUTTON_LEFT) )
            {
                x=evento.button.x;
                y=evento.button.y;


                deteccion=detectarClic(x,y,simon,orden,inicioX,inicioY);
                if(deteccion==sector)
                {
                    printf("Ha acertado.\n");
                    imprimirDeteccion(deteccion);

                    SDL_Delay(300);
                    sector=rand() % 4;
                    iluminarZona(sector,simon,orden,inicioX,inicioY,colores,renderer,B);
                }
                else
                {
                    printf("Ha perdido.\n");
                    imprimirDeteccion(deteccion);
                    salir=0;
                }

            }
        }
    }

}


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
int detectarClic(int x, int y, const int m[][ORDEN],int orden,int xMat,int yMat)
{
    int deteccion=-1;

    //x e y son las coordenadas del clic realizado en la ventana
    //xMat e yMat son las coordenadas donde inicial la matriz en pixeles a dibujarse en la ventanita
    //orden*TAM_PIXEL es el orden total de la matriz en pixeles

    if(x>=xMat && x<=xMat+orden*TAM_PIXEL && (y>=yMat && y<=yMat+orden*TAM_PIXEL))
    {
        //traduzco las coordenadas en pixeles a posiciones de la matriz
        int fila= (y-yMat)/TAM_PIXEL;
        int columna=(x-xMat)/TAM_PIXEL;

        if(fila >= 0 && fila < orden && columna >= 0 && columna < orden)
            deteccion = m[fila][columna];
    }


    return deteccion;
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
void iluminarZona(int zona,const int m[][ORDEN],int orden,int origx,int origy,SDL_Color colores[],SDL_Renderer *renderer,int zonaMod)
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





// funcion que me hace























/*while(ejecutando)
    {
        dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
        while(SDL_PollEvent(&evento))
        {
            if(evento.type == SDL_MOUSEBUTTONDOWN && evento.button.button == SDL_BUTTON_LEFT)
            {

                x=evento.button.x;
                y=evento.button.y;

                //printf("%d",simon[inicioX][inicioY]);
                deteccion=detectarClic(x,y,simon,ORDEN,inicioX,inicioY);
                imprimirDeteccion(deteccion);
            }
            srand(time(0));
            sector=rand() % 5;

            SDL_Delay(100);
            iluminarZona(sector,simonMod,ORDEN,inicioX,inicioY,colores,renderer,B);
            SDL_Delay(100);

            dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
        }
    }
*/


