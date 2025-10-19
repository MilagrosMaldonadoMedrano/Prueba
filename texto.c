#include "texto.h"
#include "math.h"

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



void cuentaRegresiva(SDL_Renderer* renderer, TTF_Font* fuente)
{
    int limite=3;
    float tiempo=0.0f;

    //char* numero[2];
    char numero[2];
    int texW,texH;

    for(int i=1;i<=limite;i++)
    {
        SDL_SetRenderDrawColor(renderer, 20, 20, 40, 255);
        SDL_RenderClear(renderer);

        Uint8 r = (Uint8)(128 +127*sin(tiempo));
        Uint8 g = (Uint8)(255 * fabs(sin(tiempo / 2)));
        Uint8 b = 255;

        SDL_Color colorCuenta = {r, g, b, 255};



        if(i==1)
        {
            //strcpy(&numero,"1\0");
            numero[0]='1';
            numero[1]='\0';
        }

        if(i==2)
        {
            numero[0]='2';
            numero[1]='\0';
        }
            //strcpy(&numero,"2");
            //numero='2';
        if(i==3)
        {
            numero[0]='3';
            numero[1]='\0';
        }
            //strcpy(&numero,"3");
            //numero='3';
        //fflush(stdin);
        //numero= i+0;

        SDL_Surface* surfCuenta= TTF_RenderText_Blended(fuente,numero,colorCuenta);
        SDL_Texture* textCuenta= SDL_CreateTextureFromSurface(renderer,surfCuenta);


        SDL_QueryTexture(textCuenta, NULL, NULL, &texW, &texH);
        SDL_Rect dstTitulo = { (1366 - texW)/2, 250, texW*2, texH*2 };

        SDL_RenderCopy(renderer, textCuenta, NULL, &dstTitulo);
        SDL_FreeSurface(surfCuenta);
        SDL_DestroyTexture(textCuenta);

        SDL_RenderPresent(renderer);
        SDL_Delay(700);
        tiempo += 0.05f;

    }


}


void mostrarTituloSimon(SDL_Renderer* renderer, TTF_Font* fuente, TTF_Font* fuente2)
{
    int ejecutando = 1;
    SDL_Event e;
    float tiempo = 0.0f;

    while (ejecutando) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                ejecutando = 0;
            else if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
                ejecutando = 0; // salir del titulo con cualquier tecla o clic
        }

        // fondo
        SDL_SetRenderDrawColor(renderer, 20, 20, 40, 255);
        SDL_RenderClear(renderer);

        // animacion de color un ciclo de brillo suave
        Uint8 r = (Uint8)(128 + 127 * sin(tiempo));
        Uint8 g = (Uint8)(255 * fabs(sin(tiempo / 2)));
        Uint8 b = 255;

        SDL_Color colorTitulo = {r, g, b, 255};
        SDL_Color colorSub = {255, 255, 255, 200};

        // render titulo principal
        const char* titulo = "SIMON DICE";
        SDL_Surface* surfTitulo = TTF_RenderText_Blended(fuente, titulo, colorTitulo);
        SDL_Texture* texTitulo = SDL_CreateTextureFromSurface(renderer, surfTitulo);

        int texW, texH;
        SDL_QueryTexture(texTitulo, NULL, NULL, &texW, &texH);
        SDL_Rect dstTitulo = { (1366 - texW)/2, 250, texW, texH };
        SDL_RenderCopy(renderer, texTitulo, NULL, &dstTitulo);

        SDL_FreeSurface(surfTitulo);
        SDL_DestroyTexture(texTitulo);

        // subtitulo
        const char* subtitulo = "Presione una tecla para comenzar";
        SDL_Surface* surfSub = TTF_RenderText_Blended(fuente2, subtitulo, colorSub);
        SDL_Texture* texSub = SDL_CreateTextureFromSurface(renderer, surfSub);

        SDL_QueryTexture(texSub, NULL, NULL, &texW, &texH);
        SDL_Rect dstSub = { (1366 - texW)/2, 500, texW, texH };
        SDL_RenderCopy(renderer, texSub, NULL, &dstSub);

        SDL_FreeSurface(surfSub);
        SDL_DestroyTexture(texSub);

        SDL_RenderPresent(renderer);

        SDL_Delay(16); // para mantener 60 fps
        tiempo += 0.05f;
    }
}
