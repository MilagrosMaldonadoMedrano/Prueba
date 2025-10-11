#include "Simon.h"
#include "texto.h"
#include "menu.h"


int simon3Colores[ORDEN][ORDEN]=
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

int simon4Colores[ORDEN][ORDEN]={
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

int simon5Colores[ORDEN][ORDEN]=
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

int simon6Colores[ORDEN][ORDEN]={
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

int simon7Colores[ORDEN][ORDEN]=
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

int simon8Colores[ORDEN][ORDEN]={
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




void simon(SDL_Renderer* renderer, const int simon[][ORDEN], Jugador* jugador)
{
    if (!sonido_ini())
        return;


    int simonRotable[ORDEN][ORDEN];
    int simonAux[ORDEN][ORDEN];
    Sonido* notas[8];
    cargarSonidos(jugador->colores,notas);//Array to pointer decay

    Simon* juego = simonCrear(jugador->colores,"Schomberg");
    if(jugador->cheat==true)
    {
        cargarSimon(simon,simonRotable);
    }


    //Para posicionar la matriz en el centro de la ventana
    int inicioX=(SCREEN_W/2)-(ORDEN*TAM_PIXEL/2);
    int inicioY=(SCREEN_H/2)-(ORDEN*TAM_PIXEL/2);

    SDL_SetRenderDrawColor(renderer, 138, 149, 151, 255); //Color turquesa
    SDL_RenderClear(renderer);    // Limpia toda la pantalla con ese color
    SDL_RenderPresent(renderer); //actualiza la ventana


    dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
    SDL_Delay(300);
    srand(time(0));


    textIni();
    TTF_Font* fuente = cargarFnt(PATH_FNT_ARIAL, TAM_FNT_MENU);

    SDL_Event evento;

    int tiempoDelay=300;


    while(juego->enJuego)
    {
        SDL_Delay(300);
        SDL_SetRenderDrawColor(renderer, 138, 149, 151, 255); //Color turquesa
        SDL_RenderClear(renderer);    // Limpia toda la pantalla con ese color
        if(jugador->cheat==true)
        {
            dibujar(renderer,simonRotable,ORDEN,ORDEN,inicioX,inicioY);
            mostrarEstadisticaSimon(renderer, fuente, jugador, juego->tam);
            SDL_RenderPresent(renderer);
            mostrarSecuencia(juego, renderer, simonRotable, inicioX, inicioY, notas,jugador->velocidad,tiempoDelay); //agregar la frecuencia
        }
        else
        {
            dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
            mostrarEstadisticaSimon(renderer, fuente, jugador, juego->tam);
            SDL_RenderPresent(renderer);
            mostrarSecuencia(juego, renderer, simon, inicioX, inicioY, notas,jugador->velocidad,tiempoDelay); //agregar la frecuencia
        }

        juego->indiceJugador = 0;

        int rondaCompletada = 0;
        while(juego->enJuego && !rondaCompletada)
        {
            while(SDL_PollEvent(&evento))
            {
                if(jugador->cheat==true)
                    rondaCompletada = procesarEntrada(juego, &evento, simonRotable, inicioX, inicioY, renderer, notas,jugador->colores,jugador->velocidad);
                else
                    rondaCompletada = procesarEntrada(juego, &evento, simon, inicioX, inicioY, renderer, notas,jugador->colores,jugador->velocidad);
            }

        }

        if(juego->enJuego)
        {
            jugador->nivel++;
            jugador->puntaje += 10 * jugador->nivel; // sistema de puntuacion

            vectorInsertarAlFinal(&juego->secuencia, rand () % jugador->colores);
            juego->tam++;
        }
        jugador->velocidad=(jugador->velocidad -(jugador->velocidad*10)/100);
        tiempoDelay=(tiempoDelay-(tiempoDelay*10)/100);
        if(jugador->cheat==true)
        {
            cargarSimon(simonRotable,simonAux);
            rotarSimon(simonAux,simonRotable);
        }

    }

    printf("Ha perdido! Nivel alcanzado %d | Puntaje: %d\n", jugador->nivel, jugador->puntaje);
    //jugador->colores = cantidad;
    //jugador->modo =
    guardarEstadistica(jugador);


    vectorDestruir(&juego->secuencia);

    for (int i = 0; i < jugador->colores; i++)
    {
        sound_free(&notas[i]); //como espera un puntero doble de la estructura Sonido le paso &notas[i]
    }
    sound_quit();

    free(juego);
}
Simon* simonCrear(int cantidad,const char* modoJuego)
{
    Simon* juego = malloc(sizeof(Simon));
    vectorCrear(&juego->secuencia);
    if(!strcmp(modoJuego,"Schomberg"))
        vectorInsertarAlFinal(&juego->secuencia, rand() % cantidad);// 1er boton
    juego->tam = 1;
    juego->indiceJugador = 0;
    juego->enJuego = 1;
    juego->cheat=false;

    return juego;
}

void mostrarSecuencia(Simon* juego, SDL_Renderer* renderer, const int simon[][ORDEN], int iniX, int iniY, Sonido** notas,float duracion,int tiempoDelay)
{
    for(int i = 0; i < juego->tam; i++)
    {

        int boton = vectorDevolverValor(&juego->secuencia, i);
        iluminarZona(boton, simon, ORDEN, iniX, iniY, renderer, B);
        sonido_play(notas[boton],duracion);
        //sonido_play(crearTonoAleatorio());
        SDL_Delay(tiempoDelay);
        dibujar(renderer, simon, ORDEN, ORDEN, iniX, iniY);
        //SDL_Delay()
        SDL_Delay(300 - (i + 1));
    }
    //LIMPIA EL BUFFER DE EVENTOS PARA NO DETECTAR NINGUN CLIC DURANTE LA SECUENCIA
    SDL_PumpEvents();
    SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
}
int procesarEntrada(Simon* juego, SDL_Event* e, const int simon[][ORDEN], int iniX, int iniY, SDL_Renderer* renderer, Sonido** notas,int cantidad,float duracion)
{
    if(e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT)
    {
        int x = e->button.x, y = e->button.y;
        int deteccion = detectarClic(x, y, simon, ORDEN, iniX, iniY);

        if(deteccion >= 0 && deteccion<cantidad)
        {
            printf("%d",deteccion);
            iluminarZona(deteccion, simon, ORDEN, iniX, iniY, renderer, N);
            sonido_play(notas[deteccion],duracion);
            //sonido_play(crearTonoAleatorio());
            SDL_Delay(150);
            dibujar(renderer, simon, ORDEN, ORDEN, iniX, iniY);

            if(deteccion == vectorDevolverValor(&juego->secuencia, juego->indiceJugador))
            {
                juego->indiceJugador++;
                if(juego->indiceJugador == juego->tam)
                {
                    return 1; // nivel completado
                }
            }
            else
            {
                juego->enJuego = 0; //perdio
            }
        }
    }
    return 0;
}
void pulsarSectorLuz(SDL_Renderer *renderer, const int m[][ORDEN], int orden)
{
    SDL_Event evento;
    int inicioX=(1000/2)-(orden*TAM_PIXEL/2);
    int inicioY=(1000/2)-(orden*TAM_PIXEL/2);
    int ejecutando=1;

    SDL_SetRenderDrawColor(renderer, 138, 149, 151, 255); //Color turquesa
    SDL_RenderClear(renderer);    // Limpia toda la pantalla con ese color
    SDL_RenderPresent(renderer); //actualiza la ventana


    int x;
    int y;
    int deteccion;
    int salir=1;
    int sector;


    dibujar(renderer,m,orden,orden,inicioX,inicioY);
    SDL_Delay(300);
    srand(time(0));
    sector=rand() % 4;
    iluminarZona(sector,m,orden,inicioX,inicioY,renderer,B);


    while(ejecutando)
    {
        SDL_Delay(150);
        dibujar(renderer,m,orden,orden,inicioX,inicioY);


        while(SDL_PollEvent(&evento) && salir==1)
        {

            if((evento.type == SDL_MOUSEBUTTONDOWN) && (evento.button.button == SDL_BUTTON_LEFT) )
            {
                x=evento.button.x;
                y=evento.button.y;


                deteccion=detectarClic(x,y,m,orden,inicioX,inicioY);
                if(deteccion==sector)
                {
                    printf("Ha acertado.\n");
                    imprimirDeteccion(deteccion);

                    SDL_Delay(300);
                    sector=rand() % 4;
                    iluminarZona(sector,m,orden,inicioX,inicioY,renderer,B);
                }
                else
                {
                    printf("Ha perdido.\n");
                    imprimirDeteccion(deteccion);
                    salir=0;
                }

            }
        }
    }

}

void rotarSimon(int simon[][ORDEN],int simonRotable[][ORDEN])
{
    for(int i=0;i<ORDEN;i++)
    {
        for(int j=0;j<ORDEN;j++)
        {
            simonRotable[i][j]=simon[ORDEN-1-j][i];
        }
    }
}

void cargarSimon(const int simon[][ORDEN],int simonRotable[][ORDEN])
{
    for(int i=0;i<ORDEN;i++)
    {
        for(int j=0;j<ORDEN;j++)
        {
            simonRotable[i][j]=simon[i][j];
        }
    }
}
void CopiarSimon(int origen[][ORDEN], int destino[][ORDEN])
{
    int i, j;

    for(i = 0; i < ORDEN; i++)
    {
        for(j = 0; j < ORDEN; j++)
            destino[i][j] = origen[i][j];
    }
}
void DeterminarJuego(Jugador * jug, SDL_Renderer *renderer)
{
    int sim[ORDEN][ORDEN];

    switch(jug->colores)
    {
        case 3:
            {
                CopiarSimon(simon3Colores, sim);
                break;
            }
        case 4:
            {
                CopiarSimon(simon4Colores, sim);
                break;
            }
        case 5:
            {
                CopiarSimon(simon5Colores, sim);
                break;
            }
        case 6:
            {
                CopiarSimon(simon6Colores, sim);
                break;
            }
        case 7:
            {
                CopiarSimon(simon7Colores, sim);
                break;
            }
        case 8:
            {
                CopiarSimon(simon8Colores, sim);
                break;
            }
    }
    switch(jug->modo)
    {
        case 0:
            {
                //desafio(renderer,sim,jug,"Secuencias/ModoDesafio4.txt");
                mozart(renderer,sim,jug,"Secuencias/ModoDesafio4.txt");
                //mozart(renderer,sim,jug,"Secuencias/Secuencia4Notas.txt");
                //simon(renderer, sim, jug);
                break;
            }
        case 1:
            {

                //mozart(renderer, simon, jug, cheat[ORDEN][ORDEN]);
                break;
            }
        case 2:
            {
                //desafio(renderer, simon, jug, cheat[ORDEN][ORDEN]);
                break;
            }

    }
}

void mozart(SDL_Renderer* renderer, const int simon[][ORDEN], Jugador* jugador,const char* nombreArchivo)
{
    if (!sonido_ini())
        return;

    Sonido* notas[8];
    cargarSonidos(jugador->colores,notas);

    Simon* juego = simonCrear(jugador->colores,"Mozart");
    int simonAux[ORDEN][ORDEN];
    int simonRotable[ORDEN][ORDEN];

    if(jugador->cheat==true)
    {
        cargarSimon(simon,simonRotable);
    }

    FILE* pArch=fopen(nombreArchivo,"rt");

    if(!pArch)
    {
        printf("Error en la apertura del archivo %s\n",nombreArchivo);
        exit(1);
    }

    //Para posicionar la matriz en el centro de la ventana
    int inicioX=(SCREEN_W/2)-(ORDEN*TAM_PIXEL/2);
    int inicioY=(SCREEN_H/2)-(ORDEN*TAM_PIXEL/2);

    SDL_SetRenderDrawColor(renderer, 138, 149, 151, 255); //Color turquesa
    SDL_RenderClear(renderer);    // Limpia toda la pantalla con ese color
    SDL_RenderPresent(renderer); //actualiza la ventana


    dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
    SDL_Delay(300);
    srand(time(0));


    textIni();
    TTF_Font* fuente = cargarFnt(PATH_FNT_ARIAL, TAM_FNT_MENU);

    SDL_Event evento;

    float duracion=2000;
    int tiempoDelay=300;


    int patron;

    fscanf(pArch,"%d;",&patron);


    while(!feof(pArch))
    {
        printf("%d\n",patron);
        vectorInsertarAlFinal(&juego->secuencia,patron);
        fscanf(pArch,"%d;",&patron);

    }

    fclose(pArch);

    while(juego->enJuego && juego->tam<=vectorDevolverCantidad(&juego->secuencia))
    {
        SDL_Delay(300);
        SDL_SetRenderDrawColor(renderer, 138, 149, 151, 255); //Color turquesa
        SDL_RenderClear(renderer);    // Limpia toda la pantalla con ese color
        if(jugador->cheat==true)
        {
            dibujar(renderer,simonRotable,ORDEN,ORDEN,inicioX,inicioY);
            mostrarEstadisticaSimon(renderer, fuente, jugador, juego->tam);
            SDL_RenderPresent(renderer);
            mostrarSecuencia(juego, renderer, simonRotable, inicioX, inicioY, notas,duracion,tiempoDelay); //agregar la frecuencia
        }
        else
        {
            dibujar(renderer,simon,ORDEN,ORDEN,inicioX,inicioY);
            mostrarEstadisticaSimon(renderer, fuente, jugador, juego->tam);
            SDL_RenderPresent(renderer);
            mostrarSecuencia(juego, renderer, simon, inicioX, inicioY, notas,duracion,tiempoDelay); //agregar la frecuencia


        }

        juego->indiceJugador = 0;

        int rondaCompletada = 0;
        while(juego->enJuego && !rondaCompletada)
        {
            while(SDL_PollEvent(&evento))
            {
                if(jugador->cheat==true)
                    rondaCompletada = procesarEntrada(juego, &evento, simonRotable, inicioX, inicioY, renderer, notas,jugador->colores,duracion);
                else
                    rondaCompletada = procesarEntrada(juego, &evento, simon, inicioX, inicioY, renderer, notas,jugador->colores,duracion);
            }

        }

        if(juego->enJuego)
        {
            jugador->nivel++;
            jugador->puntaje += 10 * jugador->nivel; // sistema de puntuacion

            //vectorInsertarAlFinal(&juego->secuencia, rand () % cantidad);
            juego->tam++;
        }
        duracion=(duracion -(duracion*10)/100);
        tiempoDelay=(tiempoDelay-(tiempoDelay*10)/100);
        if(jugador->cheat==true)
        {
            cargarSimon(simonRotable,simonAux);
            rotarSimon(simonAux,simonRotable);
        }

    }
    if(juego->tam-1==vectorDevolverCantidad(&juego->secuencia))
        printf("Ha ganado! Nivel alcanzado %d | Puntaje: %d\n", jugador->nivel, jugador->puntaje);
    else
        printf("Ha perdido! Nivel alcanzado %d | Puntaje: %d\n", jugador->nivel, jugador->puntaje);

    //guardo datos estadisticas
    //jugador->colores = cantidad;
    //jugador->modo =
    guardarEstadistica(jugador);
    vectorDestruir(&juego->secuencia);

    for (int i = 0; i < jugador->colores; i++)
    {
        sound_free(&notas[i]); //como espera un puntero doble de la estructura Sonido le paso &notas[i]
    }
    sound_quit();

    free(juego);
}

int validarEntrada(Simon* juego, SDL_Event* e, const int simon[][ORDEN],int iniX, int iniY, SDL_Renderer* renderer,Sonido** notas, int cantidad, float duracion)
{
    if (e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT)
    {
        int x = e->button.x, y = e->button.y;
        int deteccion = detectarClic(x, y, simon, ORDEN, iniX, iniY);

        if (deteccion >= 0 && deteccion < cantidad)
        {
            printf("%d", deteccion);
            iluminarZona(deteccion, simon, ORDEN, iniX, iniY, renderer, N);
            //boton_render(renderer, b, fuente);
            sonido_play(notas[deteccion], duracion);
            SDL_Delay(150);

            //dibujar(renderer, simon, ORDEN, ORDEN, iniX, iniY);

            return deteccion;
        }
    }
    return -1;
}


void desafio(SDL_Renderer* renderer, const int simon[][ORDEN], Jugador* jugador, const char* nombreArch)
{
    FILE* pArch = fopen(nombreArch, "wt");
    if (!pArch)
    {
        printf("Error en la apertura del archivo %s.\n", nombreArch);
        exit(1);
    }

    textIni();
    TTF_Font* fuente = cargarFnt(PATH_FNT_ARIAL, TAM_FNT_MENU);

    if (!sonido_ini())
        return;

    Sonido* notas[8];
    cargarSonidos(jugador->colores, notas);

    Simon* juego = simonCrear(jugador->colores, "modoDesafio");

    int inicioX = (SCREEN_W / 2) - (ORDEN * TAM_PIXEL / 2);
    int inicioY = (SCREEN_H / 2) - (ORDEN * TAM_PIXEL / 2);

    Boton b;
    boton_carga(&b, 1156, 10, 200, 50,"Finalizar",(SDL_Color){50,150,50,255},(SDL_Color){80,200,80,255},(SDL_Color){30,100,30,255});

    SDL_Event evento;
    int deteccion;
    while (juego->enJuego)
    {


        while (SDL_PollEvent(&evento))
        {
            deteccion = validarEntrada(juego, &evento, simon, inicioX, inicioY, renderer, notas, jugador->colores, 2000.0);
            if (deteccion >= 0 && deteccion < jugador->colores)
            {
                fprintf(pArch, "%d;", deteccion);
            }
            if (boton_manejo_evento(&b, &evento))
            {
                juego->enJuego = 0;
            }

        }


        SDL_SetRenderDrawColor(renderer, 138, 149, 151, 255);
        SDL_RenderClear(renderer);
        boton_render(renderer, &b, fuente);
        dibujar(renderer, simon, ORDEN, ORDEN, inicioX, inicioY);
        SDL_RenderPresent(renderer);
    }

    printf("Ha terminado!\n");
    //guardo datos estadisticas
    //jugador->colores = cantidad;
    //jugador->modo =
    guardarEstadistica(jugador);


    fclose(pArch);
    vectorDestruir(&juego->secuencia);

    for (int i = 0; i < jugador->colores; i++)
    {
        sound_free(&notas[i]);
    }

    sound_quit();
    free(juego);
}



