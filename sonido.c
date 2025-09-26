#include "sonido.h"
#include "math.h"

int sonido_ini()
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        SDL_Log("Error Mix_OpenAudio: %s", Mix_GetError());
        return 0;
    }
    return 1;
}

Sonido* sonido_carga(const char* path)
{
    Sonido* s = malloc(sizeof(Sonido));
    s->chunk = Mix_LoadWAV(path);
    if (!s->chunk)
    {
        SDL_Log("Error cargando sonido %s: %s", path, Mix_GetError());
        free(s);
        return NULL;
    }
    return s;
}

Sonido* crearTono(float frecuencia, float duracionSegundos)
{
    int samples = (int)(FREC_MUESTREO * duracionSegundos);

    // buffer de audio
    short *buffer = malloc(sizeof(short) * samples);
    if (!buffer)
    {
        SDL_Log("[Error] No se pudo reservar memoria para el tono\n");
        return NULL;
    }

    for (int i = 0; i < samples; i++)
    {
        buffer[i] = (short)(AMPLITUD_TONO * sin(2.0 * M_PI * frecuencia * i / FREC_MUESTREO));
    }

    // creamos el Mix_Chunk usando QuickLoad_RAW
    //Permite crear un Mix_Chunk directamente a partir de un buffer en memoria sin tener que inventar la estructura manualmente
    Mix_Chunk* chunk = Mix_QuickLoad_RAW((Uint8*)buffer, samples * sizeof(short));
    if (!chunk)
    {
        SDL_Log("[Error] No se pudo crear Mix_Chunk: %s\n", Mix_GetError());
        free(buffer);
        return NULL;
    }

    // empaquetamos en Sonido
    Sonido* tono = malloc(sizeof(Sonido));
    if (!tono)
    {
        SDL_Log("[Error] No se pudo reservar memoria para Sonido\n");
        Mix_FreeChunk(chunk); // libera buffer
        return NULL;
    }

    tono->chunk = chunk;
    return tono;
}



Sonido* crearTonoAleatorio()
{
    float freq;
    int min = 200, max = 1000;

    freq = min + rand() % (max - min + 1);

    return crearTono(freq, 0.3f);// 0.3 segundos
}

void sonido_play(Sonido* s)
{
    if (s && s->chunk)
        Mix_PlayChannel(-1, s->chunk, 0); // -1 = cualquier canal libre
}

void sound_free(Sonido* s)
{
    if (s)
    {
        if (s->chunk) Mix_FreeChunk(s->chunk);
        free(s);
    }
}

void sound_quit()
{
    Mix_CloseAudio();
}
