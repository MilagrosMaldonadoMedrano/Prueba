/*
Apellido: Robles, Kevin
DNI: 41261195
Entrega: Sí

Apellido: Bottarini, Matias Nicolas
DNI: 45237992
Entrega: Sí

Apellido: Maldonado Medrano, Milagros
DNI: 44182217
Entrega: Sí
*/


#include<time.h>
#include "Dibujo.h"
#include "Simon.h"
#include "sonido.h"
#include "menu.h"
#include "string.h"
#include "texto.h"

#define SCREEN_W 1366
#define SCREEN_H 768

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO); // inicia los subsistemas de audio y video

    SDL_Window *ventana  = SDL_CreateWindow("Ventana",
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           SCREEN_W,
                                           SCREEN_H,
                                           SDL_WINDOW_SHOWN);//declara la ventana del juego


    SDL_Renderer *renderer = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED); // crea el render
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); // establece su opacidad

    Configuracion usuario;
    Boton menu_botones[4];
    Jugador jugador;

    //inicializa ttf
    TTF_Init();

    // cargar fuente
    TTF_Font* fuente = TTF_OpenFont("fnt/arial.ttf", 24);
    TTF_Font* fuenteTitulo = TTF_OpenFont("fnt/Simon.ttf", 100);
    TTF_Font* fuenteSubtitulo = TTF_OpenFont("fnt/Simon.ttf", 40);
    mostrarTituloSimon(renderer, fuenteTitulo, fuenteSubtitulo);
    TTF_CloseFont(fuenteSubtitulo);

    Log_in(&usuario, renderer, fuente, fuenteTitulo);

    SDL_SetRenderDrawColor(renderer,0,0,0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    botones_menu(menu_botones, 4, SCREEN_W, SCREEN_H);//cargo los botones

    configuracionJugador(&usuario, &jugador);

    int ejecutando=1;

    SDL_Event e;
    while (ejecutando)
    {
        jugador.puntaje = 0;
        jugador.nivel = 1;
        while (SDL_PollEvent(&e))
        {
            mostrarTexto(renderer, fuenteTitulo, "SIMON", 435, 120, (SDL_Color){255, 255, 255, 0});

            if (e.type == SDL_QUIT)
                ejecutando = 0;

            for (int i = 0; i < 4; i++)//prueba el evento en cada boton
            {
                if (boton_manejo_evento(&menu_botones[i], &e))
                {
                    SDL_Log("Boton %s presionado", menu_botones[i].texto);
                    if(i == 0) // jugar
                    {
                        DeterminarJuego(&jugador, renderer);
                    }
                    if(i == 1) // configuracion
                    {
                        MenuConfiguracion(&jugador, renderer, fuente);
                    }
                    if(i == 2) // estadisiticas
                    {
                        pantallaEstadisticas(renderer, fuente);
                    }
                    if (i == 3)
                    {
                        GuardarModo(&jugador);
                        ejecutando = 0; // SALIR
                    }

                }
            }

        }


        for (int i = 0; i < 4; i++)
            boton_render(renderer, &menu_botones[i], fuente);

        SDL_RenderPresent(renderer);
    }

    printf("El jugador %s termino con %d puntos en el nivel %d\n", jugador.nombre, jugador.puntaje, jugador.nivel);



    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    TTF_CloseFont(fuente);
    TTF_CloseFont(fuenteTitulo);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
