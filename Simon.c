#include "Simon.h"





//void simon4(SDL_Renderer* renderer,const int simon[][ORDEN])
//{
//    if (!sonido_ini())
//    {
//        return;
//    }
//
//
//    Sonido* notas[6];
//    notas[0] = sonido_carga("snd/do.mp3");
//    notas[1] = sonido_carga("snd/re.mp3");
//    notas[2] = sonido_carga("snd/mi.mp3");
//    notas[3] = sonido_carga("snd/fa.mp3");
//    notas[4] = sonido_carga("snd/sol.mp3");
//    notas[5] = sonido_carga("snd/la.mp3");
//
//
//    SDL_Event evento;
//
//
//    //Para posicionar la matriz en el centro de la ventana
//    int inicioX=(SCREEN_W/2)-(ORDEN*TAM_PIXEL/2);
//    int inicioY=(SCREEN_H/2)-(ORDEN*TAM_PIXEL/2);
//    int ejecutando=1;
//
//
//    //Preparo el color del fondo
//    SDL_SetRenderDrawColor(renderer, 138, 149, 151, 255); //Color turquesa
//    SDL_RenderClear(renderer);    // Limpia toda la pantalla con ese color
//    SDL_RenderPresent(renderer); //actualiza la ventana
//
//    int x, y, deteccion, sector;
//
//    dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
//    SDL_Delay(300);
//    srand(time(0));
//    sector=rand() % 4;
//
//    Vector vDetecciones;
//    vectorCrear(&vDetecciones);
//    vectorInsertarAlFinal(&vDetecciones,sector);
//
//    int contador=1, contAux, acierto=1;
//
//
//    while(ejecutando)
//    {
//        SDL_Delay(150);
//        dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
//
//        //recorre el registro de detecciones iluminando cada zona
//        for(int i = 0; i < contador; i++)
//        {
//            SDL_Delay(300);
//            //iluminarZona(registroDetecciones[i],simon,ORDEN,inicioX,inicioY,renderer,B);
//            iluminarZona(vectorDevolverValor(&vDetecciones,i),simon,ORDEN,inicioX,inicioY,renderer,B);
//            sonido_play(notas[vectorDevolverValor(&vDetecciones,i)]);
//            SDL_Delay(300 -(i+1));
//            dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
//        }
//
//        contAux=0;
//        //aca analizo cada secuencia de clics que ejecuta el usuario
//        while(contAux<contador && acierto == 1)
//        {
//            while(SDL_PollEvent(&evento))//detecta los eventos
//            {
//                //si el evento es especificamente el clic izq lo analiza
//                if((evento.type == SDL_MOUSEBUTTONDOWN) && (evento.button.button == SDL_BUTTON_LEFT))
//                {
//                    x=evento.button.x;
//                    y=evento.button.y;
//                    deteccion=detectarClic(x,y,simon,ORDEN,inicioX,inicioY); //veo en el sector en el que se ejecutó el clic
//                    if(deteccion != -1 && deteccion!=N && deteccion!=T)
//                    {
//                        iluminarZona(deteccion,simon,ORDEN,inicioX,inicioY,renderer,N);
//                        sonido_play(notas[deteccion]);
//                        SDL_Delay(150);
//                        dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
//                        //si el sector en el que se ejecutó el clic es igual a la posisicon conAux del vector que contiene toda la secuencia aumenta el contAux, porque es un ACIERTO
//                        if(deteccion==vectorDevolverValor(&vDetecciones,contAux)) //if(deteccion==registroDetecciones[contAux])
//                        {
//                            contAux++;
//                        }
//                        else //Caso contrario el clic fue en otro sector
//                        {
//                            printf("Ha perdido!\n");
//                            acierto=0;
//                            ejecutando=0;
//                        }
//                    }
//                }
//            }
//        }
//
//        if(acierto)
//        {
//            printf("Ha acertado.\n");
//            //genero la nueva luz
//            contador++;
//            //registroDetecciones[contador]=rand() % 4;
//            vectorInsertarAlFinal(&vDetecciones,rand()%4);
//        }
//    }
//
//
//    // Liberar memoria
//    for (int i = 0; i < 6; i++)
//    {
//        sound_free(notas[i]);
//    }
//    sound_quit();
//
//}

void simon1(SDL_Renderer* renderer,const int simon[][60],int cantidad)
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



void simon(SDL_Renderer* renderer, const int simon[][60], int cantidad, Jugador* jugador)
{
    if (!sonido_ini())
        return;

    Sonido* notas[8];
    notas[0] = sonido_carga("snd/do.mp3");
    notas[1] = sonido_carga("snd/re.mp3");
    notas[2] = sonido_carga("snd/mi.mp3");
    notas[3] = sonido_carga("snd/fa.mp3");
    notas[4] = sonido_carga("snd/sol.mp3");
    notas[5] = sonido_carga("snd/la.mp3");
    notas[6] = sonido_carga("snd/sol.mp3");//acomodar estas dos ultimas notas
    notas[7] = sonido_carga("snd/la.mp3");


    Simon* juego = simonCrear(cantidad);

    //Para posicionar la matriz en el centro de la ventana
    int inicioX=(SCREEN_W/2)-(ORDEN*TAM_PIXEL/2);
    int inicioY=(SCREEN_H/2)-(ORDEN*TAM_PIXEL/2);

    SDL_SetRenderDrawColor(renderer, 138, 149, 151, 255); //Color turquesa
    SDL_RenderClear(renderer);    // Limpia toda la pantalla con ese color
    SDL_RenderPresent(renderer); //actualiza la ventana


    dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
    SDL_Delay(300);
    srand(time(0));


    SDL_Event evento;

    while(juego->enJuego)
    {
        SDL_Delay(150);
        dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
        mostrarSecuencia(juego, renderer, simon, inicioX, inicioY, notas);
        juego->indiceJugador = 0;

        int rondaCompletada = 0;
        while(juego->enJuego && !rondaCompletada)
        {
            while(SDL_PollEvent(&evento))
            {
                rondaCompletada = procesarEntrada(juego, &evento, simon, inicioX, inicioY, renderer, notas);
            }
        }

        if(juego->enJuego)
        {
            jugador->nivel++;
            jugador->puntaje += 10 * jugador->nivel; // sistema de puntuacion

            vectorInsertarAlFinal(&juego->secuencia, rand () % cantidad);
            juego->tam++;
        }
    }

    printf("Ha perdido! Nivel alcanzado %d | Puntaje: %d\n", jugador->nivel, jugador->puntaje);

    vectorDestruir(&juego->secuencia);

    for (int i = 0; i < cantidad; i++)
    {
        sound_free(notas[i]);
    }
    sound_quit();

    free(juego);
}



Simon* simonCrear(int cantidad)
{
    Simon* juego = malloc(sizeof(Simon));
    vectorCrear(&juego->secuencia);
    vectorInsertarAlFinal(&juego->secuencia, rand() % cantidad);// 1er boton
    juego->tam = 1;
    juego->indiceJugador = 0;
    juego->enJuego = 1;

    return juego;
}

void mostrarSecuencia(Simon* juego, SDL_Renderer* renderer, const int simon[][60], int iniX, int iniY, Sonido* notas[])
{
    for(int i = 0; i < juego->tam; i++)
    {
        int boton = vectorDevolverValor(&juego->secuencia, i);
        iluminarZona(boton, simon, ORDEN, iniX, iniY, renderer, B);
        sonido_play(notas[boton]);
        //sonido_play(crearTonoAleatorio());
        SDL_Delay(300);
        dibujar(renderer, simon, ORDEN, ORDEN, iniX, iniY);
        SDL_Delay(300 - (i + 1));
    }
}

int procesarEntrada(Simon* juego, SDL_Event* e, const int simon[][60], int iniX, int iniY, SDL_Renderer* renderer, Sonido* notas[])
{
    if(e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT)
    {
        int x = e->button.x, y = e->button.y;
        int deteccion = detectarClic(x, y, simon, ORDEN, iniX, iniY);

        if(deteccion >= 0)
        {
            iluminarZona(deteccion, simon, ORDEN, iniX, iniY, renderer, N);
            sonido_play(notas[deteccion]);
            //sonido_play(crearTonoAleatorio());
            SDL_Delay(150);
            dibujar(renderer, simon, ORDEN, ORDEN, iniX, iniY);

            if(deteccion == vectorDevolverValor(&juego->secuencia, juego->indiceJugador))
            {
                juego->indiceJugador++;
                if(juego->indiceJugador == juego->tam)
                {
                    return 1; // nivel completado
                }
            }
            else
            {
                juego->enJuego = 0; //perdio
            }
        }
    }
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

