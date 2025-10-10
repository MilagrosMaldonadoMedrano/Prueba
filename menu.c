#include "menu.h"
#include "texto.h"

void botones_menu(Boton* botones, int cantidad, int screen_w, int screen_h)
{
    int start_y = screen_h / 2 - (cantidad * 50 + (cantidad - 1) * 20) / 2;

    // Boton 0: JUGAR
    boton_carga(&botones[0], screen_w/2 - 100, start_y, 200, 50,
                "JUGAR",
                (SDL_Color){50,150,50,255},
                (SDL_Color){80,200,80,255},
                (SDL_Color){30,100,30,255});

    // Boton 1: CONFIGURAR
    boton_carga(&botones[1], screen_w/2 - 100, start_y + 70, 200, 50,
                "CONFIGURAR",
                (SDL_Color){50,50,150,255},
                (SDL_Color){80,80,200,255},
                (SDL_Color){30,30,100,255});

    // Boton 2: ESTADISTICAS
    boton_carga(&botones[2], screen_w/2 - 100, start_y + 140, 200, 50,
                "ESTADISTICAS",
                (SDL_Color){150,150,50,255},
                (SDL_Color){200,200,80,255},
                (SDL_Color){100,100,30,255});

    // Boton 3: SALIR
    boton_carga(&botones[3], screen_w/2 - 100, start_y + 210, 200, 50,
                "SALIR",
                (SDL_Color){150,50,50,255},
                (SDL_Color){200,80,80,255},
                (SDL_Color){100,30,30,255});
}


void boton_carga(Boton* b, int x, int y, int w, int h, char* texto, SDL_Color normal, SDL_Color encima, SDL_Color presionado)
{
    b->rect.x = x;
    b->rect.y = y;
    b->rect.w = w;
    b->rect.h = h;
    b->texto = texto;
    b->color = normal;
    b->encima_color = encima;
    b->presionado_color = presionado;
    b->encima = 0;
    b->presionado = 0;
}

void boton_render(SDL_Renderer* renderer, Boton* b, TTF_Font* fuente)
{
    SDL_Color c = b->color;
    if (b->presionado)
        c = b->presionado_color;
    else if
        (b->encima) c = b->encima_color;

    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    SDL_RenderFillRect(renderer, &b->rect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &b->rect);


    // --- Renderizar texto ---
    SDL_Surface* surface = TTF_RenderText_Blended(fuente, b->texto, (SDL_Color)
    {
        255,255,255,255
    });
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

    // Centrar el texto dentro del botón
    SDL_Rect dst;
    dst.x = b->rect.x + (b->rect.w - texW) / 2;
    dst.y = b->rect.y + (b->rect.h - texH) / 2;
    dst.w = texW;
    dst.h = texH;

    SDL_RenderCopy(renderer, texture, NULL, &dst);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

int boton_manejo_evento(Boton* b, SDL_Event* e)
{
    if (e->type == SDL_MOUSEMOTION)
    {
        int x = e->motion.x, y = e->motion.y;
        b->encima = (x >= b->rect.x && x <= b->rect.x + b->rect.w &&
                     y >= b->rect.y && y <= b->rect.y + b->rect.h);
    }
    else if (e->type == SDL_MOUSEBUTTONDOWN && b->encima)
    {
        b->presionado = 1;
        return 1; // Botón activado
    }
    else if (e->type == SDL_MOUSEBUTTONUP)
    {
        b->presionado = 0;
    }
    return 0;
}

int input_manejo_evento(Input *i, SDL_Event *e)
{
    int x = e->motion.x, y = e->motion.y, pos = 0;
    if(x >= i->rect.x && x <= i->rect.x + i->rect.w && y >= i->rect.y && y <= i->rect.y + i->rect.h)
    {
        pos = 1;
    }

    if (e->type == SDL_MOUSEBUTTONDOWN && pos)
    {
        i->activo = 1;
        return 1; // Botón activado
    }
    else if (e->type == SDL_MOUSEBUTTONDOWN && !pos)
        i->activo = 0;
    return 0;
}

void Log_in(Configuracion *usuario, SDL_Renderer *renderer, TTF_Font* fuente)
{
    SDL_StartTextInput();
    Boton boton;
    Input input;

    boton_carga(&boton, SCREEN_W/2 - 150, SCREEN_H/2 + 75, 300, 50,
                "Ingresar",
                (SDL_Color){50,150,50,255},
                (SDL_Color){80,200,80,255},
                (SDL_Color){30,100,30,255});

    input_carga(&input, SCREEN_W/2 - 150, SCREEN_H/2 - 100, 300, 50, "",(SDL_Color){255,255,255,0});

    SDL_Event evento;

    while(boton.presionado == 0)
    {
        while(SDL_PollEvent(&evento))
        {
            if(boton_manejo_evento(&boton, &evento))
            {
                if(!CorroborarUsuario(input.texto, usuario))
                    printf("Problemas al abrir el archivo.\n");
            }
            input_manejo_evento(&input, &evento);
            EscribirPalabra(&evento, &input);
        }
        SDL_SetRenderDrawColor(renderer, 36, 9, 66, 255);
        SDL_RenderClear(renderer);
        mostrarTexto(renderer, fuente, "Nombre:", 420, 300, (SDL_Color){255, 255, 255, 0});

        boton_render(renderer, &boton, fuente);
        input_render(renderer, &input, fuente);
        SDL_RenderPresent(renderer);
    }

    SDL_StopTextInput();
    SDL_RenderClear(renderer);
}


bool CorroborarUsuario(char* usu, Configuracion *usuario)
{
    FILE *pf = fopen("Usuarios.bin", "r+b");
    Configuracion lect;
    if(!pf)
    {
        printf("Error al abrir el archivo.\n");
        return false;
    }
    fread(&lect, sizeof(Configuracion), 1, pf);
    while(!feof(pf))
    {
        if(!strcmp(lect.usuario, usu))
        {
            usuario->colores = lect.colores;
            usuario->modo = lect.modo;
            usuario->velocidad = lect.velocidad;
            usuario->cheat = lect.cheat;
            strcpy(usuario->usuario, usu);
            return true;
        }
        fread(&lect, sizeof(Configuracion), 1, pf);
    }
    fseek(pf, 0, 2);
    usuario->colores = 4;
    usuario->modo = 0;
    usuario->velocidad = 2000;
    usuario->cheat = false;
    strcpy(usuario->usuario, usu);
    fwrite(usuario, sizeof(Configuracion), 1, pf);
    fclose(pf);
    return true;
}

void EscribirPalabra(SDL_Event *evento, Input * campo)
{
    if(campo)
    {
        if (evento->type == SDL_TEXTINPUT)
        {
        // Verifica longitud máxima
            if (strlen(campo->texto) + strlen(evento->text.text) < MAX_LENGTH)
            {
                strcat(campo->texto, evento->text.text);
            }
        }
        if (evento->type == SDL_KEYDOWN)
        {
        // Manejo de Backspace
            if (evento->key.keysym.sym == SDLK_BACKSPACE && strlen(campo->texto) > 0)
            {
                campo->texto[strlen(campo->texto) - 1] = '\0'; // Eliminar último carácter
            }
        }
    }
}

void input_carga(Input* i, int x, int y, int w, int h, char* texto, SDL_Color normal)
{
    i->rect.x = x;
    i->rect.y = y;
    i->rect.w = w;
    i->rect.h = h;
    strcpy(i->texto, texto);
    i->color = normal;
    i->activo = 0;
    return;
}

void input_render(SDL_Renderer* renderer, Input* i, TTF_Font* fuente)
{
    SDL_Color c = i->color;

    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    SDL_RenderFillRect(renderer, &i->rect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &i->rect);


    // --- Renderizar texto ---
    SDL_Surface* surface = TTF_RenderText_Solid(fuente, i->texto, (SDL_Color)
    {
        255,255,255,255
    });
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

    // Centrar el texto dentro del botón
    SDL_Rect dst;
    dst.x = i->rect.x + 10;
    dst.y = i->rect.y + (i->rect.h - texH) / 2;
    dst.w = texW;
    dst.h = texH;

    SDL_RenderCopy(renderer, texture, NULL, &dst);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void configuracionJugador(Configuracion *usu, Jugador* jug)
{
    strcpy(jug->nombre, usu->usuario);
    jug->colores = usu->colores;
    jug->modo = usu->modo;
    jug->velocidad = usu->velocidad;
    jug->cheat = usu->cheat;
}

void GuardarModo(Jugador * jugador)
{
    Configuracion usuario;
    FILE *pf = fopen("Usuarios.bin", "r+b");
    if(!pf)
    {
        printf("Error al abrir el archivo.\n");
    }
    fread(&usuario, sizeof(Configuracion), 1, pf);
    while(!feof(pf))
    {
        if(!strcmp(usuario.usuario, jugador->nombre))
        {
            usuario.colores = jugador->colores;
            usuario.modo = jugador->modo;
            usuario.velocidad = jugador->velocidad;
            usuario.cheat = jugador->cheat;
            fseek(pf, -(int)(sizeof(Configuracion)), 1);
            fwrite(&usuario, sizeof(Configuracion), 1, pf);
            fclose(pf);
            return;
        }
        fread(&usuario, sizeof(Configuracion), 1, pf);
    }

}
