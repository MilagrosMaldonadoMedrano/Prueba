#include "sonido.h"

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
