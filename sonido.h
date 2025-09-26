#ifndef SONIDO_H_INCLUDED
#define SONIDO_H_INCLUDED

#define FREC_MUESTREO 44100
#define AMPLITUD_TONO 8192

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

typedef struct
{
    Mix_Chunk* chunk;  // para efectos cortos (notas del Simon)
} Sonido;

int sonido_ini();
Sonido* sonido_carga(const char* path);
void sonido_play(Sonido* s);
Sonido* crearTono(float frecuencia, float duracionSegundos);
Sonido* crearTonoAleatorio();
void sound_free(Sonido* s);
void sound_quit();

#endif // SONIDO_H_INCLUDED
