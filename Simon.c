#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define SCREEN_W 1366
#define SCREEN_H 768
#include "Dibujo.h"
#include "Vector.h"
#include "Funciones.h"
#include "sonido.h"


void simon4(SDL_Renderer* renderer,const int simon[][ORDEN])
{
    if (!sonido_ini())
    {
        return;
    }


    Sonido* notas[6];
    notas[0] = sonido_carga("snd/do.mp3");
    notas[1] = sonido_carga("snd/re.mp3");
    notas[2] = sonido_carga("snd/mi.mp3");
    notas[3] = sonido_carga("snd/fa.mp3");
    notas[4] = sonido_carga("snd/sol.mp3");
    notas[5] = sonido_carga("snd/la.mp3");


    SDL_Event evento;


    //Para posicionar la matriz en el centro de la ventana
    int inicioX=(SCREEN_W/2)-(ORDEN*TAM_PIXEL/2);
    int inicioY=(SCREEN_H/2)-(ORDEN*TAM_PIXEL/2);
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

    Vector vDetecciones;
    vectorCrear(&vDetecciones);
    vectorInsertarAlFinal(&vDetecciones,sector);

    int contador=1, contAux, acierto=1;


    while(ejecutando)
    {
        SDL_Delay(150);
        dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);

        //recorre el registro de detecciones iluminando cada zona
        for(int i = 0; i < contador; i++)
        {
            SDL_Delay(300);
            //iluminarZona(registroDetecciones[i],simon,ORDEN,inicioX,inicioY,renderer,B);
            iluminarZona(vectorDevolverValor(&vDetecciones,i),simon,ORDEN,inicioX,inicioY,renderer,B);
            sonido_play(notas[vectorDevolverValor(&vDetecciones,i)]);
            SDL_Delay(300 -(i+1));
            dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
        }

        contAux=0;
        //aca analizo cada secuencia de clics que ejecuta el usuario
        while(contAux<contador && acierto == 1)
        {
            while(SDL_PollEvent(&evento))//detecta los eventos
            {
                //si el evento es especificamente el clic izq lo analiza
                if((evento.type == SDL_MOUSEBUTTONDOWN) && (evento.button.button == SDL_BUTTON_LEFT))
                {
                    x=evento.button.x;
                    y=evento.button.y;
                    deteccion=detectarClic(x,y,simon,ORDEN,inicioX,inicioY); //veo en el sector en el que se ejecutó el clic
                    if(deteccion != -1 && deteccion!=N && deteccion!=T)
                    {
                        iluminarZona(deteccion,simon,ORDEN,inicioX,inicioY,renderer,N);
                        sonido_play(notas[deteccion]);
                        SDL_Delay(150);
                        dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
                        //si el sector en el que se ejecutó el clic es igual a la posisicon conAux del vector que contiene toda la secuencia aumenta el contAux, porque es un ACIERTO
                        if(deteccion==vectorDevolverValor(&vDetecciones,contAux)) //if(deteccion==registroDetecciones[contAux])
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
            //registroDetecciones[contador]=rand() % 4;
            vectorInsertarAlFinal(&vDetecciones,rand()%4);
        }
    }


    // Liberar memoria
    for (int i = 0; i < 6; i++)
    {
        sound_free(notas[i]);
    }
    sound_quit();

}

void simon(SDL_Renderer* renderer,const int simon[][60],int cantidad)
{
    if (!sonido_ini())
    {
        return;
    }


    Sonido* notas[8];
    notas[0] = sonido_carga("snd/do.mp3");
    notas[1] = sonido_carga("snd/re.mp3");
    notas[2] = sonido_carga("snd/mi.mp3");
    notas[3] = sonido_carga("snd/fa.mp3");
    notas[4] = sonido_carga("snd/sol.mp3");
    notas[5] = sonido_carga("snd/la.mp3");
    notas[6] = sonido_carga("snd/sol.mp3");//acomodar estas dos ultimas notas
    notas[7] = sonido_carga("snd/la.mp3");

    SDL_Event evento;


    //Para posicionar la matriz en el centro de la ventana
    int inicioX=(SCREEN_W/2)-(ORDEN*TAM_PIXEL/2);
    int inicioY=(SCREEN_H/2)-(ORDEN*TAM_PIXEL/2);
    int ejecutando=1;


    //Preparo el color del fondo
    SDL_SetRenderDrawColor(renderer, 138, 149, 151, 255); //Color turquesa
    SDL_RenderClear(renderer);    // Limpia toda la pantalla con ese color
    SDL_RenderPresent(renderer); //actualiza la ventana

    int x, y, deteccion, sector;

    dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
    SDL_Delay(300);
    srand(time(0));
    sector=rand() % cantidad;

    Vector vDetecciones;
    vectorCrear(&vDetecciones);
    vectorInsertarAlFinal(&vDetecciones,sector);

    int contador=1, contAux, acierto=1;


    while(ejecutando)
    {
        SDL_Delay(150);
        dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);

        //recorre el registro de detecciones iluminando cada zona
        for(int i = 0; i < contador; i++)
        {
            SDL_Delay(300);
            //iluminarZona(registroDetecciones[i],simon,ORDEN,inicioX,inicioY,renderer,B);
            iluminarZona(vectorDevolverValor(&vDetecciones,i),simon,ORDEN,inicioX,inicioY,renderer,B);
            sonido_play(crearTonoAleatorio());
            //sonido_play(notas[vectorDevolverValor(&vDetecciones,i)]);
            SDL_Delay(300 -(i+1));
            dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
        }

        contAux=0;
        //aca analizo cada secuencia de clics que ejecuta el usuario
        while(contAux<contador && acierto == 1)
        {
            while(SDL_PollEvent(&evento))//detecta los eventos
            {
                //si el evento es especificamente el clic izq lo analiza
                if((evento.type == SDL_MOUSEBUTTONDOWN) && (evento.button.button == SDL_BUTTON_LEFT))
                {
                    x=evento.button.x;
                    y=evento.button.y;
                    deteccion=detectarClic(x,y,simon,ORDEN,inicioX,inicioY); //veo en el sector en el que se ejecutó el clic
                    if(deteccion != -1 && deteccion!=N && deteccion!=T)
                    {
                        iluminarZona(deteccion,simon,ORDEN,inicioX,inicioY,renderer,N);
                        sonido_play(crearTonoAleatorio());
                        //sonido_play(notas[deteccion]);
                        SDL_Delay(150);
                        dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
                        //si el sector en el que se ejecutó el clic es igual a la posisicon conAux del vector que contiene toda la secuencia aumenta el contAux, porque es un ACIERTO
                        if(deteccion==vectorDevolverValor(&vDetecciones,contAux)) //if(deteccion==registroDetecciones[contAux])
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
            vectorInsertarAlFinal(&vDetecciones,rand()%cantidad);
        }
    }


    // Liberar memoria
    for (int i = 0; i < cantidad; i++)
    {
        sound_free(notas[i]);
    }
    sound_quit();

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


    dibujar(renderer,m,orden,orden,inicioX,inicioY);
    SDL_Delay(300);
    srand(time(0));
    sector=rand() % 4;
    iluminarZona(sector,m,orden,inicioX,inicioY,renderer,B);


    while(ejecutando)
    {
        SDL_Delay(150);
        dibujar(renderer,m,orden,orden,inicioX,inicioY);


        while(SDL_PollEvent(&evento) && salir==1)
        {

            if((evento.type == SDL_MOUSEBUTTONDOWN) && (evento.button.button == SDL_BUTTON_LEFT) )
            {
                x=evento.button.x;
                y=evento.button.y;


                deteccion=detectarClic(x,y,m,orden,inicioX,inicioY);
                if(deteccion==sector)
                {
                    printf("Ha acertado.\n");
                    imprimirDeteccion(deteccion);

                    SDL_Delay(300);
                    sector=rand() % 4;
                    iluminarZona(sector,m,orden,inicioX,inicioY,renderer,B);
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

