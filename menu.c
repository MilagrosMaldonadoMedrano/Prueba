#include "menu.h"

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
                (SDL_Color)
    {
        50,50,150,255
    },
    (SDL_Color)
    {
        80,80,200,255
    },
    (SDL_Color)
    {
        30,30,100,255
    });

    // Boton 2: ESTADISTICAS
    boton_carga(&botones[2], screen_w/2 - 100, start_y + 140, 200, 50,
                "ESTADISTICAS",
                (SDL_Color)
    {
        150,150,50,255
    },
    (SDL_Color)
    {
        200,200,80,255
    },
    (SDL_Color)
    {
        100,100,30,255
    });

    // Boton 3: SALIR
    boton_carga(&botones[3], screen_w/2 - 100, start_y + 210, 200, 50,
                "SALIR",
                (SDL_Color)
    {
        150,50,50,255
    },
    (SDL_Color)
    {
        200,80,80,255
    },
    (SDL_Color)
    {
        100,30,30,255
    });
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
