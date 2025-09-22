#ifndef SONIDO_H_INCLUDED
#define SONIDO_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

typedef struct
{
    Mix_Chunk* chunk;  // para efectos cortos (notas del Simon)
} Sonido;

int sonido_ini();
Sonido* sonido_carga(const char* path);
void sonido_play(Sonido* s);
void sound_free(Sonido* s);
void sound_quit();

#endif // SONIDO_H_INCLUDED
