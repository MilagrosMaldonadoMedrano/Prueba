#include "Simon.h"
#include "texto.h"



void simon(SDL_Renderer* renderer, const int simon[][ORDEN], int cantidad, Jugador* jugador,int simonRotable[][ORDEN])
{
    if (!sonido_ini())
        return;

    Sonido* notas[8];
    cargarSonidos(cantidad,notas);//Array to pointer decay

    Simon* juego = simonCrear(cantidad);
    if(juego->cheat==true)
    {
        cargarSimon(simon,simonRotable);
    }


    //Para posicionar la matriz en el centro de la ventana
    int inicioX=(SCREEN_W/2)-(ORDEN*TAM_PIXEL/2);
    int inicioY=(SCREEN_H/2)-(ORDEN*TAM_PIXEL/2);

    SDL_SetRenderDrawColor(renderer, 138, 149, 151, 255); //Color turquesa
    SDL_RenderClear(renderer);    // Limpia toda la pantalla con ese color
    SDL_RenderPresent(renderer); //actualiza la ventana


    dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
    SDL_Delay(300);
    srand(time(0));


    textIni();
    TTF_Font* fuente = cargarFnt(PATH_FNT_ARIAL, TAM_FNT_MENU);

    SDL_Event evento;

    float duracion=2000;
    int tiempoDelay=300;
    int simonAux[ORDEN][ORDEN];

    while(juego->enJuego)
    {
        SDL_Delay(300);
        SDL_SetRenderDrawColor(renderer, 138, 149, 151, 255); //Color turquesa
        SDL_RenderClear(renderer);    // Limpia toda la pantalla con ese color
        if(juego->cheat==true)
        {
            dibujar(renderer,simonRotable,ORDEN,ORDEN,inicioX,inicioY);
            mostrarEstadisticaSimon(renderer, fuente, jugador, juego->tam);
            SDL_RenderPresent(renderer);
            mostrarSecuencia(juego, renderer, simonRotable, inicioX, inicioY, notas,duracion,tiempoDelay); //agregar la frecuencia
        }
        else
        {
            dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
            mostrarEstadisticaSimon(renderer, fuente, jugador, juego->tam);
            SDL_RenderPresent(renderer);
            mostrarSecuencia(juego, renderer, simon, inicioX, inicioY, notas,duracion,tiempoDelay); //agregar la frecuencia


        }

        juego->indiceJugador = 0;

        int rondaCompletada = 0;
        while(juego->enJuego && !rondaCompletada)
        {
            while(SDL_PollEvent(&evento))
            {
                if(juego->cheat==true)
                    rondaCompletada = procesarEntrada(juego, &evento, simonRotable, inicioX, inicioY, renderer, notas,cantidad,duracion);
                else
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
        if(juego->cheat==true)
        {
            cargarSimon(simonRotable,simonAux);
            rotarSimon(simonAux,simonRotable);
        }

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
    //vectorInsertarAlFinal(&juego->secuencia, rand() % cantidad);// 1er boton
    juego->tam = 1;
    juego->indiceJugador = 0;
    juego->enJuego = 1;
    juego->cheat=false;

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
    //LIMPIA EL BUFFER DE EVENTOS PARA NO DETECTAR NINGUN CLIC DURANTE LA SECUENCIA
    SDL_PumpEvents();
    SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
}
int procesarEntrada(Simon* juego, SDL_Event* e, const int simon[][ORDEN], int iniX, int iniY, SDL_Renderer* renderer, Sonido** notas,int cantidad,float duracion)
{
    if(e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT)
    {
        int x = e->button.x, y = e->button.y;
        int deteccion = detectarClic(x, y, simon, ORDEN, iniX, iniY);

        if(deteccion >= 0 && deteccion<cantidad)
        {
            printf("%d",deteccion);
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

void rotarSimon(int simon[][ORDEN],int simonRotable[][ORDEN])
{
    for(int i=0;i<ORDEN;i++)
    {
        for(int j=0;j<ORDEN;j++)
        {
            simonRotable[i][j]=simon[ORDEN-1-j][i];
        }
    }
}

void cargarSimon(const int simon[][ORDEN],int simonRotable[][ORDEN])
{
    for(int i=0;i<ORDEN;i++)
    {
        for(int j=0;j<ORDEN;j++)
        {
            simonRotable[i][j]=simon[i][j];
        }
    }
}

void mozart(SDL_Renderer* renderer, const int simon[][ORDEN], int cantidad, Jugador* jugador,int simonRotable[][ORDEN],char* nombreArchivo)
{

    //recordar  ue en crear simon comente una linea importante para que funcione el modo mozart



    if (!sonido_ini())
        return;

    Sonido* notas[8];
    cargarSonidos(cantidad,notas);//Array to pointer decay

    Simon* juego = simonCrear(cantidad);
    if(juego->cheat==true)
    {
        cargarSimon(simon,simonRotable);
    }

    FILE* pArch=fopen(nombreArchivo,"rt");

    if(!pArch)
    {
        printf("Error en la apertura del archivo %s/n",nombreArchivo);
        exit(1);
    }

    //Para posicionar la matriz en el centro de la ventana
    int inicioX=(SCREEN_W/2)-(ORDEN*TAM_PIXEL/2);
    int inicioY=(SCREEN_H/2)-(ORDEN*TAM_PIXEL/2);

    SDL_SetRenderDrawColor(renderer, 138, 149, 151, 255); //Color turquesa
    SDL_RenderClear(renderer);    // Limpia toda la pantalla con ese color
    SDL_RenderPresent(renderer); //actualiza la ventana


    dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
    SDL_Delay(300);
    srand(time(0));


    textIni();
    TTF_Font* fuente = cargarFnt(PATH_FNT_ARIAL, TAM_FNT_MENU);

    SDL_Event evento;

    float duracion=2000;
    int tiempoDelay=300;
    int simonAux[ORDEN][ORDEN];

    int patron;

    fscanf(pArch,"%d",&patron);

    while(!feof(pArch))
    {
        printf("%d\n",patron);
        vectorInsertarAlFinal(&juego->secuencia,patron);
        fscanf(pArch,"%d",&patron);

    }

    fclose(pArch);

    while(juego->enJuego && juego->tam<=vectorDevolverCantidad(&juego->secuencia))
    {
        SDL_Delay(300);
        SDL_SetRenderDrawColor(renderer, 138, 149, 151, 255); //Color turquesa
        SDL_RenderClear(renderer);    // Limpia toda la pantalla con ese color
        if(juego->cheat==true)
        {
            dibujar(renderer,simonRotable,ORDEN,ORDEN,inicioX,inicioY);
            mostrarEstadisticaSimon(renderer, fuente, jugador, juego->tam);
            SDL_RenderPresent(renderer);
            mostrarSecuencia(juego, renderer, simonRotable, inicioX, inicioY, notas,duracion,tiempoDelay); //agregar la frecuencia
        }
        else
        {
            dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
            mostrarEstadisticaSimon(renderer, fuente, jugador, juego->tam);
            SDL_RenderPresent(renderer);
            mostrarSecuencia(juego, renderer, simon, inicioX, inicioY, notas,duracion,tiempoDelay); //agregar la frecuencia


        }

        juego->indiceJugador = 0;

        int rondaCompletada = 0;
        while(juego->enJuego && !rondaCompletada)
        {
            while(SDL_PollEvent(&evento))
            {
                if(juego->cheat==true)
                    rondaCompletada = procesarEntrada(juego, &evento, simonRotable, inicioX, inicioY, renderer, notas,cantidad,duracion);
                else
                    rondaCompletada = procesarEntrada(juego, &evento, simon, inicioX, inicioY, renderer, notas,cantidad,duracion);
            }

        }

        if(juego->enJuego)
        {
            jugador->nivel++;
            jugador->puntaje += 10 * jugador->nivel; // sistema de puntuacion

            //vectorInsertarAlFinal(&juego->secuencia, rand () % cantidad);
            juego->tam++;
        }
        duracion=(duracion -(duracion*10)/100);
        tiempoDelay=(tiempoDelay-(tiempoDelay*10)/100);
        if(juego->cheat==true)
        {
            cargarSimon(simonRotable,simonAux);
            rotarSimon(simonAux,simonRotable);
        }

    }
    if(juego->tam==vectorDevolverCantidad(&juego->secuencia))
        printf("Ha ganado! Nivel alcanzado %d | Puntaje: %d\n", jugador->nivel, jugador->puntaje);
    else
        printf("Ha perdido! Nivel alcanzado %d | Puntaje: %d\n", jugador->nivel, jugador->puntaje);

    vectorDestruir(&juego->secuencia);

    for (int i = 0; i < cantidad; i++)
    {
        sound_free(&notas[i]); //como espera un puntero doble de la estructura Sonido le paso &notas[i]
    }
    sound_quit();

    free(juego);
}





