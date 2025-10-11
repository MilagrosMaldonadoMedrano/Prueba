#include<time.h>
#include "Dibujo.h"
#include "Simon.h"
#include "sonido.h"
#include "menu.h"
#include "string.h"
#include "texto.h"
#include "funciones.h"

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

    // Cargar fuente
    TTF_Font* fuente = TTF_OpenFont("fnt/arial.ttf", 24);

    SDL_SetRenderDrawColor(renderer, 36, 9, 66, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    Log_in(&usuario, renderer, fuente);

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

            if (e.type == SDL_QUIT)
                ejecutando = 0;

            for (int i = 0; i < 4; i++)//Prueba el evento en cada boton
            {
                if (boton_manejo_evento(&menu_botones[i], &e))
                {
                    SDL_Log("Boton %s presionado", menu_botones[i].texto);
                    if(i == 0)
                    {
                        DeterminarJuego(&jugador, renderer);


                    }
                    if(i == 1)
                    {
                        //simon(renderer, simon3Colores, 3, &jugador);
                        //simon(renderer,simon8Colores,8,&jugador,simonRotable);
                        //simon(renderer,simon5Colores,5);
                        //simon(renderer,simon3Colores,3);
                        //simon(renderer,simon6Colores,6);
                        //simon1(renderer,simon7Colores,7);
                    }
                    if(i == 2)
                    {
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
    TTF_Quit();
    SDL_Quit();

    return 0;
}
