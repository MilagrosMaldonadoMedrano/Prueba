#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include<time.h>


#include "Dibujo.h"
#include "Simon.h"

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
                                           1000,
                                           1000,
                                           SDL_WINDOW_SHOWN);//declara la ventana del juego


    SDL_Renderer *renderer = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED); // crea el render
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); // establece su opacidad



    //FUNCION JUEGO BASICO
    //pulsarSectorLuz(renderer,simon4Colores,ORDEN);



    simon4(renderer,simon4Colores);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    SDL_Quit();

    return 0;
}
