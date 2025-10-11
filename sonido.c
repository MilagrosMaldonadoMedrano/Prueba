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

void sonido_play(Sonido* s,float duracion)
{
    if (s && s->chunk)
        Mix_PlayChannelTimed(-1, s->chunk, 0, duracion);
        //Mix_PlayChannel(-1, s->chunk, 0); // -1 = cualquier canal libre
}

void sound_free(Sonido** s)
{
    if (s)
    {
        if ((*s)->chunk) Mix_FreeChunk((*s)->chunk);
        free(*s);
    }
}

void sound_quit()
{
    Mix_CloseAudio();
}


//void cargarSonidos(int cantidad,Sonido** vSimon)
//{
//
//    if(cantidad==3)
//    {
//        vSimon[0]=sonido_carga("snd/do.mp3");
//        vSimon[1]=sonido_carga("snd/mi.mp3");
//        vSimon[2]=sonido_carga("snd/sol.mp3");
//    }
//
//    if(cantidad==4)
//    {
//        vSimon[0]=sonido_carga("snd/do.mp3");
//        vSimon[1]=sonido_carga("snd/mi.mp3");
//        vSimon[2]=sonido_carga("snd/sol.mp3");
//        vSimon[3]=sonido_carga("snd/la.mp3");
//    }
//
//    if(cantidad==5)
//    {
//        vSimon[0]=sonido_carga("snd/do.mp3");
//        vSimon[1]=sonido_carga("snd/re.mp3");
//        vSimon[2]=sonido_carga("snd/mi.mp3");
//        vSimon[3]=sonido_carga("snd/sol.mp3");
//        vSimon[4]=sonido_carga("snd/la.mp3");
//    }
//
//    if(cantidad==6)
//    {
//        vSimon[0]=sonido_carga("snd/do.mp3");
//        vSimon[1]=sonido_carga("snd/re.mp3");
//        vSimon[2]=sonido_carga("snd/mi.mp3");
//        vSimon[3]=sonido_carga("snd/FA#.mp3");
//        vSimon[4]=sonido_carga("snd/SOL#.mp3");
//        vSimon[5]=sonido_carga("snd/LA#.mp3");
//
//    }
//
//    if(cantidad==7)
//    {
//
//        vSimon[0]=sonido_carga("snd/do.mp3");
//        vSimon[1]=sonido_carga("snd/re.mp3");
//        vSimon[2]=sonido_carga("snd/Mib.mp3");
//        vSimon[3]=sonido_carga("snd/fa.mp3");
//        vSimon[4]=sonido_carga("snd/sol.mp3");
//        vSimon[5]=sonido_carga("snd/lab.mp3");
//        vSimon[6]=sonido_carga("snd/si.mp3");
//
//    }
//
//    if(cantidad==8)
//    {
//
//        vSimon[0]=sonido_carga("snd/do.mp3");
//        vSimon[1]=sonido_carga("snd/re.mp3");
//        vSimon[2]=sonido_carga("snd/mi.mp3");
//        vSimon[3]=sonido_carga("snd/fa.mp3");
//        vSimon[4]=sonido_carga("snd/sol.mp3");
//        vSimon[5]=sonido_carga("snd/la.mp3");
//        vSimon[6]=sonido_carga("snd/si.mp3");
//        vSimon[7]=sonido_carga("snd/do_2.mp3");
//    }
//}


void cargarSonidos(int cantidad, Sonido** vSimon)
{
    const char* sonidos[8][8] = {
        // simon 1–2 solo para mantener indice
        {"", "", "", "", "", "", "", ""},
        {"", "", "", "", "", "", "", ""},

        // simon 3
        {"snd/do.mp3", "snd/mi.mp3", "snd/sol.mp3"},
        // simon 4
        {"snd/do.mp3", "snd/mi.mp3", "snd/sol.mp3", "snd/la.mp3"},
        // simon 5
        {"snd/do.mp3", "snd/re.mp3", "snd/mi.mp3", "snd/sol.mp3", "snd/la.mp3"},
        // simon 6
        {"snd/do.mp3", "snd/re.mp3", "snd/mi.mp3", "snd/FA#.mp3", "snd/SOL#.mp3", "snd/LA#.mp3"},
        // simon 7
        {"snd/do.mp3", "snd/re.mp3", "snd/Mib.mp3", "snd/fa.mp3", "snd/sol.mp3", "snd/lab.mp3", "snd/si.mp3"},
        // simon 8
        {"snd/do.mp3", "snd/re.mp3", "snd/mi.mp3", "snd/fa.mp3", "snd/sol.mp3", "snd/la.mp3", "snd/si.mp3", "snd/do_2.mp3"}
    };


    if (cantidad < 3 || cantidad > 8) {
        return;
    }

    // Carga los sonidos segun la cantidad
    for (int i = 0; i < cantidad; i++) {
        const char* ruta = sonidos[cantidad][i];
        if (ruta && ruta[0] != '\0') {
            vSimon[i] = sonido_carga(ruta);
        } else {
            vSimon[i] = NULL;
        }
    }
}




/*Sonido* modificarTiempoSonido(float duracion,Sonido *s)
{
    Mix_PlayChannelTimed(-1, s->chunk, 0, duracion);
}
*/
