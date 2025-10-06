#include<time.h>
#include "Dibujo.h"
#include "Simon.h"
#include "sonido.h"
#include "menu.h"
#include "string.h"
#include "texto.h"

#define SCREEN_W 1366
#define SCREEN_H 768


const int simon3Colores[ORDEN][ORDEN]=
{
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,R,R,R,R,N,A,A,A,A,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,R,R,R,R,R,R,R,R,N,A,A,A,A,A,A,A,A,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,N,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,R,N,A,A,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T},
    {T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T},
    {T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T},
    {T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,N,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,N,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,N,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,N,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},

};

const int simon4Colores[ORDEN][ORDEN]={
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T,T,T,T,T,T},
    {T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T,T,T,T,T},
    {T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T,T,T,T},
    {T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T,T,T},
    {T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T,T},
    {T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T},
    {N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N},
    {N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,N,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N},
    {N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,N,N,N,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N},
    {N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,N,N,N,N,N,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N},
    {N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,N,N,N,N,N,N,N,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N},
    {N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,N,N,N,N,N,N,N,N,N,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N},
    {N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N},
    {N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N},
    {N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N},
    {N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N},
    {N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N},
    {N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N},
    {N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N},
    {N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,N,N,N,N,N,N,N,N,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N},
    {N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,N,N,N,N,N,N,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N},
    {N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,N,N,N,N,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N},
    {N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,N,N,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N},
    {N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N},
    {N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N},
    {T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T},
    {T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T},
    {T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T},
    {T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T},
    {T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T}
};

const int simon5Colores[ORDEN][ORDEN]=
{
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,V,V,V,V,N,O,O,O,O,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,V,V,V,V,V,V,V,V,N,O,O,O,O,O,O,O,O,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,N,O,O,O,O,O,O,O,O,O,O,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,N,O,O,O,O,O,O,O,O,O,O,O,O,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,N,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,N,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,N,R,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,A,A,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,R,R,R,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,A,A,A,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,N,R,R,R,R,R,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,A,A,A,A,A,N,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,N,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,A,A,A,A,A,A,N,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,N,N,V,V,V,V,V,V,V,V,V,V,V,V,N,O,O,O,O,O,O,O,O,O,O,O,O,N,N,A,A,A,A,A,A,A,A,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,N,N,V,V,V,V,V,V,V,V,V,V,V,N,O,O,O,O,O,O,O,O,O,O,O,N,N,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,N,N,V,V,V,V,V,V,V,V,V,V,N,O,O,O,O,O,O,O,O,O,O,N,N,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,N,N,V,V,V,V,V,V,V,V,V,N,O,O,O,O,O,O,O,O,O,N,N,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,V,V,V,V,V,V,V,V,N,O,O,O,O,O,O,O,O,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T},
    {T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,V,V,V,V,V,V,V,N,O,O,O,O,O,O,O,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T},
    {T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,V,V,V,V,V,V,N,O,O,O,O,O,O,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,V,V,V,V,V,N,O,O,O,O,O,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,V,V,V,V,N,O,O,O,O,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,V,V,V,N,O,O,O,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,N,N,N,N,N,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,N,N,N,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,N,N,N,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,N,N,N,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,N,N,N,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T},
    {T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,N,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,N,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,N,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,N,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,N,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
};

const int simon6Colores[ORDEN][ORDEN]={
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,N,W,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,N,N,W,W,W,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,N,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,N,W,W,W,W,W,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,N,N,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,N,N,W,W,W,W,W,W,W,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,N,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,N,W,W,W,W,W,W,W,W,W,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,N,N,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,N,N,W,W,W,W,W,W,W,W,W,W,W,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,N,N,T,T,T,T,T,T},
    {T,T,T,T,T,N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T,T,T,T,T},
    {T,T,T,T,N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T,T,T,T},
    {T,T,T,N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T,T,T},
    {T,T,N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,V,V,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T,T},
    {T,N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,V,V,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,T},
    {N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,V,V,V,V,V,V,V,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N},
    {N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,N,N,N,N,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N},
    {N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,N,N,N,N,N,N,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N},
    {N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,N,N,N,N,N,N,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N},
    {N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,N,N,N,N,N,N,N,N,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N},
    {N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,N,N,N,N,N,N,N,N,N,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N},
    {N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N},
    {N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N},
    {N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N},
    {N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N},
    {N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N},
    {N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N},
    {N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N},
    {N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,N,N,N,N,N,N,N,N,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N},
    {N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,N,N,N,N,N,N,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N},
    {N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,N,N,N,N,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N},
    {N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,N,N,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N},
    {N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,N,N,N,N,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N},
    {N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N},
    {T,N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T},
    {T,T,N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T},
    {T,T,T,N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T},
    {T,T,T,T,N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T},
    {T,T,T,T,T,N,N,O,O,O,O,O,O,O,O,O,O,O,O,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,N,O,O,O,O,O,O,O,O,O,O,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,N,O,O,O,O,O,O,O,O,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,N,N,O,O,O,O,O,O,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,N,O,O,O,O,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,N,N,O,O,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T}
};

const int simon7Colores[ORDEN][ORDEN]=
{
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,O,O,O,O,O,O,O,O,O,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,N,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,N,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,C,C,C,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,V,V,V,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,N,C,C,C,C,C,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,V,V,V,V,V,N,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,C,C,C,C,C,C,C,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,V,V,V,V,V,V,V,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,C,C,C,C,C,C,C,C,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,V,V,V,V,V,V,V,V,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,N,C,C,C,C,C,C,C,C,C,C,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,V,V,V,V,V,V,V,V,V,V,N,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,N,C,C,C,C,C,C,C,C,C,C,C,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,V,V,V,V,V,V,V,V,V,V,V,N,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,C,C,C,C,C,C,C,C,C,C,C,C,C,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,V,V,V,V,V,V,V,V,V,V,V,V,V,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,C,C,C,C,C,C,C,C,C,C,C,C,C,C,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,N,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,N,O,O,O,O,O,O,O,O,O,O,O,O,O,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,N,O,O,O,O,O,O,O,O,O,O,O,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,N,O,O,O,O,O,O,O,O,O,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,T,T,T,T,T},
    {T,T,T,T,T,N,N,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,N,O,O,O,O,O,O,O,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,T,T,T,T},
    {T,T,T,T,T,N,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,N,O,O,O,O,O,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,T,T,T,T},
    {T,T,T,T,T,N,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,N,O,O,O,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,T,T,T,T},
    {T,T,T,T,T,N,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,N,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,T,T,T,T},
    {T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T},
    {T,T,T,T,T,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,R,N,Z,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,R,R,N,Z,Z,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,R,R,R,N,Z,Z,Z,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,R,R,R,R,N,Z,Z,Z,Z,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T},
    {T,T,T,T,T,N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,R,R,R,R,R,N,Z,Z,Z,Z,Z,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T},
    {T,T,T,T,T,T,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,R,R,R,R,R,R,N,Z,Z,Z,Z,Z,Z,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,R,R,R,R,R,R,R,N,Z,Z,Z,Z,Z,Z,Z,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,R,R,R,R,R,R,R,R,N,Z,Z,Z,Z,Z,Z,Z,Z,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,W,W,W,W,W,W,W,W,W,W,W,W,N,R,R,R,R,R,R,R,R,R,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,A,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,W,W,W,W,W,W,W,W,W,W,W,N,R,R,R,R,R,R,R,R,R,R,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,A,A,A,A,A,A,A,A,A,A,A,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,N,W,W,W,W,W,W,W,W,W,N,R,R,R,R,R,R,R,R,R,R,R,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,A,A,A,A,A,A,A,A,A,N,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,N,W,W,W,W,W,W,W,W,N,R,R,R,R,R,R,R,R,R,R,R,R,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,A,A,A,A,A,A,A,A,N,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,W,W,W,W,W,W,N,R,R,R,R,R,R,R,R,R,R,R,R,R,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,A,A,A,A,A,A,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,W,W,W,W,W,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,A,A,A,A,A,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,N,W,W,W,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,A,A,A,N,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,R,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,R,R,R,R,R,R,R,R,N,Z,Z,Z,Z,Z,Z,Z,Z,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,R,R,R,R,N,Z,Z,Z,Z,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T}

};

const int simon8Colores[ORDEN][ORDEN]={
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,N,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,N,N,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,N,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,N,W,W,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,N,N,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,N,N,W,W,W,W,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,N,N,T,T,T,T,T,T},
    {T,T,T,T,T,N,N,W,W,W,W,W,W,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,N,N,T,T,T,T,T},
    {T,T,T,T,N,N,W,W,W,W,W,W,W,W,N,N,R,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,N,N,T,T,T,T},
    {T,T,T,N,N,W,W,W,W,W,W,W,W,W,W,N,N,R,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,N,N,T,T,T},
    {T,T,N,N,W,W,W,W,W,W,W,W,W,W,W,W,N,N,R,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,N,N,T,T},
    {T,N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,R,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,T},
    {N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,R,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N,N},
    {N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,R,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N},
    {N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,R,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N},
    {N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,R,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N},
    {N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,R,R,R,R,R,N,N,Z,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N},
    {N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,R,R,R,R,N,N,Z,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N},
    {N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,R,R,R,N,N,Z,Z,Z,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N},
    {N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,N,N,N,N,N,N,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N},
    {N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,N,N,N,N,N,N,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N},
    {N,N,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,N,N,N,N,N,N,N,N,N,N,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,N,N},
    {N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N},
    {N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,N,N,N,N,N,N,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N},
    {N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,N,N,N,N,N,N,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N},
    {N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,N,N,N,N,N,N,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N},
    {N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,N,N,N,N,N,N,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N},
    {N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,C,C,C,N,N,P,P,P,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N},
    {N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,C,C,C,C,N,N,P,P,P,P,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N},
    {N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,C,C,C,C,C,N,N,P,P,P,P,P,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N},
    {N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,C,C,C,C,C,C,N,N,P,P,P,P,P,P,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N},
    {N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,C,C,C,C,C,C,C,N,N,P,P,P,P,P,P,P,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N},
    {N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,C,C,C,C,C,C,C,C,N,N,P,P,P,P,P,P,P,P,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N},
    {T,N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,C,C,C,C,C,C,C,C,C,N,N,P,P,P,P,P,P,P,P,P,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,T},
    {T,T,N,N,O,O,O,O,O,O,O,O,O,O,O,O,O,N,N,C,C,C,C,C,C,C,C,C,C,N,N,P,P,P,P,P,P,P,P,P,P,N,N,V,V,V,V,V,V,V,V,V,V,V,V,V,N,N,T,T},
    {T,T,T,N,N,O,O,O,O,O,O,O,O,O,O,O,N,N,C,C,C,C,C,C,C,C,C,C,C,N,N,P,P,P,P,P,P,P,P,P,P,P,N,N,V,V,V,V,V,V,V,V,V,V,V,N,N,T,T,T},
    {T,T,T,T,N,N,O,O,O,O,O,O,O,O,O,N,N,C,C,C,C,C,C,C,C,C,C,C,C,N,N,P,P,P,P,P,P,P,P,P,P,P,P,N,N,V,V,V,V,V,V,V,V,V,N,N,T,T,T,T},
    {T,T,T,T,T,N,N,O,O,O,O,O,O,O,N,N,C,C,C,C,C,C,C,C,C,C,C,C,C,N,N,P,P,P,P,P,P,P,P,P,P,P,P,P,N,N,V,V,V,V,V,V,V,N,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,N,O,O,O,O,O,N,N,C,C,C,C,C,C,C,C,C,C,C,C,C,C,N,N,P,P,P,P,P,P,P,P,P,P,P,P,P,P,N,N,V,V,V,V,V,N,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,N,O,O,O,N,N,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,N,N,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,N,N,V,V,V,N,N,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,N,N,O,N,N,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,N,N,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,N,N,V,N,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,N,N,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,N,N,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,N,N,N,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,N,N,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,N,N,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,N,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,N,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,N,N,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,N,N,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,N,N,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,N,N,P,P,P,P,P,P,P,P,P,P,P,P,P,P,P,N,N,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,C,C,C,C,C,C,C,C,C,C,C,C,C,C,N,N,P,P,P,P,P,P,P,P,P,P,P,P,P,P,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,C,C,C,C,C,C,C,C,C,C,C,C,C,N,N,P,P,P,P,P,P,P,P,P,P,P,P,P,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,C,C,C,C,C,C,C,C,C,C,C,C,N,N,P,P,P,P,P,P,P,P,P,P,P,P,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,C,C,C,C,C,C,C,C,C,C,C,N,N,P,P,P,P,P,P,P,P,P,P,P,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,C,C,C,C,C,C,C,C,C,C,N,N,P,P,P,P,P,P,P,P,P,P,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T}
};

const int circulo[ORDEN][ORDEN]=
{
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,T,T,T,T,T,T,T,T,T,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T},
    {T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T},
    {T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T},
    {T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T},
    {T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T},
    {T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T},
    {T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T},
    {T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T},
    {T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T},
    {T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T},
    {T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T},
    {T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T},
    {T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,T,T,T,T,T,T,T,T,T,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,N,N,N,N,N,N,N,N,N,N,N,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T,T}

};
const int fondo[21][21]=
{
    {V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0},
    {V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0},
    {V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0},
    {V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0},
    {V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0},
    {V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0,V0},
    {V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1},
    {V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1},
    {V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1},
    {V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1},
    {V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1,V1},
    {V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2},
    {V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2},
    {V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2},
    {V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2},
    {V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2,V2},
    {V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3},
    {V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3},
    {V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3},
    {V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3},
    {V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3,V3}
};



int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO); // inicia los subsistemas de audio y video

    SDL_Window *ventana  = SDL_CreateWindow("Ventana",
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           SCREEN_W,
                                           SCREEN_H,
                                           SDL_WINDOW_SHOWN);//declara la ventana del juego


    SDL_Renderer *renderer = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED); // crea el render
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); // establece su opacidad



    Boton menu_botones[4];
    botones_menu(menu_botones, 4, SCREEN_W, SCREEN_H);//cargo los botones

    Boton conf_botones[7];
    botones_configuracion(conf_botones,7,SCREEN_W, SCREEN_H);

    textIni();//inicia ttf
    TTF_Font* fuente = cargarFnt(PATH_FNT_ARIAL, TAM_FNT_MENU);// Cargar fuente




    SDL_SetRenderDrawColor(renderer, 36, 9, 66, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);


    Jugador jugador;

    strcpy(jugador.nombre, "KEVIN");
    jugador.nivel = 0;
    jugador.puntaje = 0;


    int ejecutando=1;

    int estadoPantalla=1;   //EstadoPantalla en 0==Nombre
                           //EstadoPantalla en 1==Menu
                          //EstadoPantalla en 2==CONF



    SDL_Event e;
    while (ejecutando)
    {

        while (SDL_PollEvent(&e))
        {

            if (e.type == SDL_QUIT)
                ejecutando = 0;

            if (estadoPantalla == 0) // Pedir nombre
            {
                //if(e.type==SDL_TEXTINPUT)
                   // strcat(Jugador->nombre, e.text.text);
            }


            if(estadoPantalla==1)
            {
                for (int i = 0; i < 4; i++)//Prueba el evento en cada boton
                {
                    if (boton_manejo_evento(&menu_botones[i], &e))
                    {
                        SDL_Log("Boton %s presionado", menu_botones[i].texto);
                        if(i == 0)
                        {
                            simon(renderer, simon4Colores, 4, &jugador);
                        }
                        if(i == 1) //Configuracion
                        {
                            SDL_Log("Boton %s presionado", menu_botones[i].texto);
                            estadoPantalla=2;
                        }
                        if(i == 2)
                        {
                            SDL_Log("Boton %s presionado", menu_botones[i].texto);
                            estadoPantalla=2;
                        }
                        if (i == 3)
                        {
                            ejecutando = 0; // SALIR
                        }

                    }
                }

            }
            if(estadoPantalla==2) //configuraciones
            {
                //campo_evento(&campo, &e);
                for(int j=0; j<7;j++)
                {
                   if (boton_manejo_evento(&conf_botones[j], &e))
                    {
                        SDL_Log("Boton %s presionado", conf_botones[j].texto);

                        if(j==0)
                        {
                            ingresarNombre(renderer, fuente, &jugador);
                            simon(renderer, simon3Colores, 3, &jugador);
                        }
                        if(j==1)
                            simon(renderer, simon4Colores, 4, &jugador);
                        if(j==2)
                            simon(renderer, simon5Colores, 5, &jugador);
                        if(j==3)
                            simon(renderer, simon6Colores, 6, &jugador);
                        if(j==4)
                            simon(renderer, simon7Colores, 7, &jugador);
                        if(j==5)
                            simon(renderer, simon8Colores, 8, &jugador);
                        if(j==6)
                            estadoPantalla=1;

                    }
                }
            }
        }

        if(estadoPantalla==3)
        {

        }


        SDL_SetRenderDrawColor(renderer, 36, 9, 66, 255);
        SDL_RenderClear(renderer);



        if(estadoPantalla==1)
        {
            for (int i = 0; i < 4; i++)
                boton_render(renderer, &menu_botones[i], fuente);
        }


        if(estadoPantalla==2)
        {
            for (int i = 0; i < 7; i++)
                boton_render(renderer, &conf_botones[i], fuente);
             //if (campo.activo)
                //campo_render(renderer, &campo);
        }

        SDL_RenderPresent(renderer);
    }

    printf("El jugador %s termino con %d puntos en el nivel %d\n", jugador.nombre, jugador.puntaje, jugador.nivel);



    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    TTF_CloseFont(fuente);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
