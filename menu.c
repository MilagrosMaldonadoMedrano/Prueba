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
    int band = 0;
    SDL_SetRenderDrawColor(renderer, 36, 9, 66, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_StartTextInput();
    Boton boton[2];
    Input input[2], *campo_activo;

    boton_carga(&boton[1], SCREEN_W/2 - 150, SCREEN_H/2 + 75, 300, 50,
                "Iniciar sesion",
                (SDL_Color){50,150,50,255},
                (SDL_Color){80,200,80,255},
                (SDL_Color){30,100,30,255});

    boton_carga(&boton[0], SCREEN_W/2 - 140, SCREEN_H/2, 280, 45,
                "No tengo cuenta",
                (SDL_Color){150,50,50,255},
                (SDL_Color){200,0,80,255},
                (SDL_Color){100,30,30,255});
    input_carga(&input[0], SCREEN_W/2 - 150, SCREEN_H/2 - 150, 300, 50, "",(SDL_Color){255,255,255,0});
    input_carga(&input[1], SCREEN_W/2 - 150, SCREEN_H/2 - 77, 300, 50, "",(SDL_Color){255,255,255,0});

    SDL_Event evento;

    while(boton[0].presionado == 0 && boton[1].presionado == 0)
    {
        campo_activo = NULL;
        if (input[0].activo)
        {
            campo_activo = &input[0];
        }
        else if (input[1].activo) campo_activo = &input[1];

        while(SDL_PollEvent(&evento))
        {
            for(int i = 0; i < 2; i++)
            {
                if(boton_manejo_evento(&boton[i], &evento))
                {
                    if(i == 1)
                    {//Presionó inicio de sesion
                        if(!CorroborarUsuario(input[0].texto, input[1].texto, usuario))
                        {
                            band = 1;
                            boton[1].presionado = 0;
                        }
                    }
                    else
                    {//Presionó que no tiene cuenta
                        CrearCuenta(usuario, renderer, fuente);
                    }
                }
                input_manejo_evento(&input[i], &evento);
            }
            EscribirPalabra(&evento, campo_activo);

        }
        SDL_SetRenderDrawColor(renderer, 36, 9, 66, 255);
        SDL_RenderClear(renderer);
        mostrarTexto(renderer, fuente, input[0].texto, 550, 245, (SDL_Color){0, 0, 0, 255});
        mostrarTexto(renderer, fuente, input[1].texto, 550, 315, (SDL_Color){0, 0, 0, 255});
        mostrarTexto(renderer, fuente, "Usuario:", 420, 245, (SDL_Color){255, 255, 255, 0});
        mostrarTexto(renderer, fuente, "Clave:", 395, 315, (SDL_Color){255, 255, 255, 0});
        if(band)
            mostrarTexto(renderer, fuente, "Cuenta no valida", 600, 200, (SDL_Color){255, 255, 255, 0});

        boton_render(renderer, &boton[0], fuente);
        boton_render(renderer, &boton[1], fuente);
        input_render(renderer, &input[0], fuente);
        input_render(renderer, &input[1], fuente);
        SDL_RenderPresent(renderer);
    }

    SDL_StopTextInput();
    SDL_RenderClear(renderer);
}

void CrearCuenta(Configuracion *usuario, SDL_Renderer *renderer, TTF_Font* fuente)
{
    int band = 0;
    SDL_SetRenderDrawColor(renderer, 36, 9, 66, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    Boton boton[2];
    Input input[2], *campo_activo;

    boton_carga(&boton[1], SCREEN_W/2 - 150, SCREEN_H/2 + 75, 300, 50,
                "Crear Cuenta", (SDL_Color){50,150,50,255}, (SDL_Color){80,200,80,255}, (SDL_Color){30,100,30,255});

    boton_carga(&boton[0], SCREEN_W/2 - 140, SCREEN_H/2, 280, 45,
                "Ya tengo cuenta", (SDL_Color){150,50,50,255}, (SDL_Color){200,0,80,255}, (SDL_Color){100,30,30,255});
    input_carga(&input[0], SCREEN_W/2 - 150, SCREEN_H/2 - 150, 300, 50, "",(SDL_Color){255,255,255,0});
    input_carga(&input[1], SCREEN_W/2 - 150, SCREEN_H/2 - 77, 300, 50, "",(SDL_Color){255,255,255,0});

    SDL_Event evento;

    while(boton[0].presionado == 0 && boton[1].presionado == 0)
    {
        campo_activo = NULL;
        if (input[0].activo)
        {
            campo_activo = &input[0];
        }
        else if (input[1].activo) campo_activo = &input[1];

        while(SDL_PollEvent(&evento))
        {
            for(int i = 0; i < 2; i++)
            {
                if(boton_manejo_evento(&boton[i], &evento))
                {
                    if(i == 1)
                    {//Presionó Crear Cuenta
                        if(strlen(input[0].texto) > 0 && strlen(input[1].texto) > 0)
                        {
                            if(!CorroborarNuevoUsuario(input[0].texto, input[1].texto, usuario))
                            {
                                band = 1;
                                boton[1].presionado = 0;
                            }
                        }
                        else
                        {
                            band = 2;
                            boton[1].presionado = 0;
                        }
                    }
                    else
                    {//Presionó que ya tiene cuenta
                        Log_in(usuario, renderer, fuente);
                    }
                }
                input_manejo_evento(&input[i], &evento);
            }
            EscribirPalabra(&evento, campo_activo);
        }

        SDL_SetRenderDrawColor(renderer, 36, 9, 66, 255);
        SDL_RenderClear(renderer);
        mostrarTexto(renderer, fuente, input[0].texto, 550, 245, (SDL_Color){0, 0, 0, 255});
        mostrarTexto(renderer, fuente, input[1].texto, 550, 315, (SDL_Color){0, 0, 0, 255});
        mostrarTexto(renderer, fuente, "Usuario:", 420, 245, (SDL_Color){255, 255, 255, 0});
        mostrarTexto(renderer, fuente, "Clave:", 395, 315, (SDL_Color){255, 255, 255, 0});
        if(band == 1)
            mostrarTexto(renderer, fuente, "Usuario ya existente", 580, 200, (SDL_Color){255, 255, 255, 0});
        else if(band == 2)
            mostrarTexto(renderer, fuente, "Completar ambos casilleros", 550, 200, (SDL_Color){255, 255, 255, 0});

        boton_render(renderer, &boton[0], fuente);
        boton_render(renderer, &boton[1], fuente);
        input_render(renderer, &input[0], fuente);
        input_render(renderer, &input[1], fuente);
        SDL_RenderPresent(renderer);
    }
}

bool CorroborarUsuario(char* usu,char* cont,Configuracion *usuario)
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
        if(!strcmp(lect.usuario, usu) && !strcmp(lect.contra, cont))
        {
            usuario->colores = lect.colores;
            usuario->modo = lect.modo;
            usuario->velocidad = lect.velocidad;
            strcpy(usuario->contra, cont);
            strcpy(usuario->usuario, usu);
            return true;
        }
        fread(&lect, sizeof(Configuracion), 1, pf);
    }
    fclose(pf);
    return false;
}

bool CorroborarNuevoUsuario(char* usu,char* cont,Configuracion *usuario)
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
            return false;
        }
        fread(&lect, sizeof(Configuracion), 1, pf);
    }
    usuario->colores = 4;
    usuario->modo = 0;
    usuario->velocidad = 2000;
    strcpy(usuario->contra, cont);
    strcpy(usuario->usuario, usu);
    fseek(pf,0,2);
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
}

