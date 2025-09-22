#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL_ttf.h>
#include<time.h>

#define SCREEN_W 1366
#define SCREEN_H 768


#include "Dibujo.h"
#include "Simon.h"
#include "sonido.h"
#include "menu.h"

const int simon4Colores[ORDEN][ORDEN] = {
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

/*const int luz[][]
{

};*/

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO); // inicia los subsistemas de audio y video

    SDL_Window *ventana  = SDL_CreateWindow("Ventanita",
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           SCREEN_W,
                                           SCREEN_H,
                                           SDL_WINDOW_SHOWN);//declara la ventana del juego


    SDL_Renderer *renderer = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED); // crea el render
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); // establece su opacidad



    Boton menu_botones[4];
    botones_menu(menu_botones, 4, SCREEN_W, SCREEN_H);//cargo los botones

    //inicializa ttf
    if (TTF_Init() == -1)
    {
        SDL_Log("Error al inicializar SDL_ttf: %s", TTF_GetError());
        return 1;
    }

    // Cargar fuente
    TTF_Font* fuente = TTF_OpenFont("fnt/arial.ttf", 24);
    if (!fuente)
    {
        SDL_Log("No se pudo cargar fuente: %s", TTF_GetError());
        return 1;
    }


    //FUNCION JUEGO BASICO
    //pulsarSectorLuz(renderer,simon4Colores,ORDEN);


    int ejecutando=1;

    SDL_Event e;
    while (ejecutando)
    {

        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT) ejecutando = 0;

            for (int i = 0; i < 4; i++)
            {
                if (boton_manejo_evento(&menu_botones[i], &e))
                {
                    SDL_Log("Boton %s presionado", menu_botones[i].texto);
                    if(i == 0)
                    {
                        simon4(renderer,simon4Colores);

                    }
                    if(i == 1)
                    {

                    }
                    if(i == 2)
                    {

                    }
                    if (i == 3)
                    {
                        ejecutando = 0; // SALIR
                    }

                }
            }

        }


        for (int i = 0; i < 4; i++)
            boton_render(renderer, &menu_botones[i], fuente);

        SDL_RenderPresent(renderer);
    }



    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    TTF_CloseFont(fuente);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
