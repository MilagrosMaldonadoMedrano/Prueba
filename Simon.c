#include "Simon.h"





void simon(SDL_Renderer* renderer, const int simon[][ORDEN], int cantidad, Jugador* jugador)
{
    if (!sonido_ini())
        return;

    /*Sonido* notas[8];
    notas[0] = sonido_carga("snd/do.mp3");
    notas[1] = sonido_carga("snd/re.mp3");
    notas[2] = sonido_carga("snd/mi.mp3");
    notas[3] = sonido_carga("snd/fa.mp3");
    notas[4] = sonido_carga("snd/sol.mp3");
    notas[5] = sonido_carga("snd/la.mp3");
    notas[6] = sonido_carga("snd/sol.mp3");//acomodar estas dos ultimas notas
    notas[7] = sonido_carga("snd/la.mp3");*/

    Sonido* notas[8];
    cargarSonidos(cantidad,notas);//Array to pointer decay


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

    float duracion=2000;
    int tiempoDelay=300;

    while(juego->enJuego)
    {
        SDL_Delay(300);
        dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
        mostrarSecuencia(juego, renderer, simon, inicioX, inicioY, notas,duracion,tiempoDelay); //agregar la frecuencia

        juego->indiceJugador = 0;

        int rondaCompletada = 0;
        while(juego->enJuego && !rondaCompletada)
        {
            while(SDL_PollEvent(&evento))
            {
                rondaCompletada = procesarEntrada(juego, &evento, simon, inicioX, inicioY, renderer, notas,cantidad,duracion);
            }
        }

        if(juego->enJuego)
        {
            jugador->nivel++;
            jugador->puntaje += 10 * jugador->nivel; // sistema de puntuacion

            vectorInsertarAlFinal(&juego->secuencia, rand () % cantidad);
            juego->tam++;
        }
        duracion=(duracion -(duracion*10)/100);
        tiempoDelay=(tiempoDelay-(tiempoDelay*10)/100);
    }

    printf("Ha perdido! Nivel alcanzado %d | Puntaje: %d\n", jugador->nivel, jugador->puntaje);

    vectorDestruir(&juego->secuencia);

    for (int i = 0; i < cantidad; i++)
    {
        sound_free(&notas[i]); //como espera un puntero doble de la estructura Sonido le paso &notas[i]
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

void mostrarSecuencia(Simon* juego, SDL_Renderer* renderer, const int simon[][ORDEN], int iniX, int iniY, Sonido** notas,float duracion,int tiempoDelay)
{
    for(int i = 0; i < juego->tam; i++)
    {

        int boton = vectorDevolverValor(&juego->secuencia, i);
        iluminarZona(boton, simon, ORDEN, iniX, iniY, renderer, B);
        sonido_play(notas[boton],duracion);
        //sonido_play(crearTonoAleatorio());
        SDL_Delay(tiempoDelay);
        dibujar(renderer, simon, ORDEN, ORDEN, iniX, iniY);
        //SDL_Delay()
        SDL_Delay(300 - (i + 1));
    }
}

int procesarEntrada(Simon* juego, SDL_Event* e, const int simon[][ORDEN], int iniX, int iniY, SDL_Renderer* renderer, Sonido** notas,int cantidad,float duracion)
{
    if(e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT)
    {
        int x = e->button.x, y = e->button.y;
        int deteccion = detectarClic(x, y, simon, ORDEN, iniX, iniY);

        if(deteccion >= 0 && deteccion<cantidad)
        {
            iluminarZona(deteccion, simon, ORDEN, iniX, iniY, renderer, N);
            sonido_play(notas[deteccion],duracion);
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

