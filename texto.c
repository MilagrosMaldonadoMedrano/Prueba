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
    SDL_Surface* superficie = TTF_RenderText_Solid(fnt, texto, color);
    SDL_Texture* textura = SDL_CreateTextureFromSurface(renderer, superficie);

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
