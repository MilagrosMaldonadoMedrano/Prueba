#include "texto.h"

int textIni()
{
    //inicializa ttf
    if (TTF_Init() == -1)
    {
        SDL_Log("Error al inicializar SDL_ttf: %s", TTF_GetError());
        exit(1);
        //return 1;
    }
    return 0;
}

TTF_Font* cargarFnt(const char* path, int tamFnt)
{
    TTF_Font* fuente = TTF_OpenFont(path, tamFnt);
    if (!fuente)
    {
        SDL_Log("No se pudo cargar fuente: %s", TTF_GetError());
        exit(1);
        //return 1;
    }
    return fuente;
}



void mostrarTexto(SDL_Renderer* renderer, TTF_Font* fnt, const char* texto, int x, int y, SDL_Color color)
{
    if(!renderer || !fnt || !texto || texto[0] == '\0')
        return;//no dibuja nada si no hay texto

    SDL_Surface* superficie = TTF_RenderText_Solid(fnt, texto, color);
    if(!superficie)
    {
        SDL_Log("Error al crear surface de texto: %s", TTF_GetError());
        return;
    }
    SDL_Texture* textura = SDL_CreateTextureFromSurface(renderer, superficie);
    if(!textura)
    {
        SDL_Log("Error al crear textura de texto: %s", SDL_GetError());
        SDL_FreeSurface(superficie);
        return;
    }


    SDL_Rect rect = {x, y, superficie->w, superficie->h};
    SDL_RenderCopy(renderer, textura, NULL, &rect);

    SDL_FreeSurface(superficie);
    SDL_DestroyTexture(textura);
}


void mostrarEstadisticaSimon(SDL_Renderer* renderer, TTF_Font* fnt, Jugador* jugador, int nivelSimon)
{
    SDL_Color blanco = {255,255,255,255};
    char buffer[128];

    snprintf(buffer, sizeof(buffer), "Jugador: %s", jugador->nombre);
    mostrarTexto(renderer, fnt, buffer, 20, 20, blanco);

    snprintf(buffer, sizeof(buffer), "Puntaje: %d", jugador->puntaje);
    mostrarTexto(renderer, fnt, buffer, 20, 60, blanco);

    snprintf(buffer, sizeof(buffer), "Nivel: %d", nivelSimon);
    mostrarTexto(renderer, fnt, buffer, 20, 100, blanco);
}



void ingresarNombre(SDL_Renderer* renderer, TTF_Font* fnt, Jugador* jugador)
{
    SDL_Event e;
    int ingresando = 1;

    jugador->nombre[0] = '\0'; //me aseguro de que arranque vacio


    SDL_StartTextInput();

    while(ingresando)
    {
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
            {
                ingresando = 0;
            }
            else if(e.type == SDL_TEXTINPUT)
            {
                if(strlen(jugador->nombre) + strlen(e.text.text) < sizeof(jugador->nombre) - 1)
                {
                    strcat(jugador->nombre, e.text.text);
                }
            }
            else if(e.type == SDL_KEYDOWN)
            {
                if(e.key.keysym.sym == SDLK_BACKSPACE && strlen(jugador->nombre) > 0)//detecta el espacio
                {
                    jugador->nombre[strlen(jugador->nombre) - 1] = '\0';//detecta enter
                }
                else if(e.key.keysym.sym == SDLK_RETURN)
                {
                    ingresando = 0;// confirma y sale
                }
            }

        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        mostrarTexto(renderer, fnt, "Ingrese su nombre ", 100, 150, (SDL_Color){255, 255, 255, 255});
        mostrarTexto(renderer, fnt, jugador->nombre, 100, 200, (SDL_Color){255, 255, 255, 255});

        SDL_RenderPresent(renderer);
    }
    SDL_StopTextInput();
}
