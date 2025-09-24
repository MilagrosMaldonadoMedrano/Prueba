#include<time.h>
#include "Dibujo.h"
#include "Simon.h"
#include "sonido.h"
#include "menu.h"
#define SCREEN_W 1366
#define SCREEN_H 768



//modificar el delay del clic cuando se ejecuta el recorrido del vectorSecuencia
//ORDEN 51
const int simon4Colores[60][60]={
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

/*
const int simon4Colores[ORDEN][ORDEN] = {
    {T,T,T,T,T,T,T,N,N,N,N,N,N,N,T,T,T,T,T,T,T},
    {T,T,T,T,T,T,N,V,V,V,N,R,R,R,N,T,T,T,T,T,T},
    {T,T,T,T,T,N,V,V,V,V,N,R,R,R,R,N,T,T,T,T,T},
    {T,T,T,T,N,V,V,V,V,V,N,R,R,R,R,R,N,T,T,T,T},
    {T,T,T,N,V,V,V,V,V,V,N,R,R,R,R,R,R,N,T,T,T},
    {T,T,N,V,V,V,V,V,V,V,N,R,R,R,R,R,R,R,N,T,T},
    {T,N,V,V,V,V,V,V,V,V,N,R,R,R,R,R,R,R,R,N,T},
    {N,V,V,V,V,V,V,V,V,V,N,R,R,R,R,R,R,R,R,R,N},
    {N,V,V,V,V,V,V,V,V,N,N,N,R,R,R,R,R,R,R,R,N},
    {N,V,V,V,V,V,V,V,N,N,N,N,N,R,R,R,R,R,R,R,N},
    {N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N},
    {N,A,A,A,A,A,A,A,N,N,N,N,N,Z,Z,Z,Z,Z,Z,Z,N},
    {N,A,A,A,A,A,A,A,A,N,N,N,Z,Z,Z,Z,Z,Z,Z,Z,N},
    {N,A,A,A,A,A,A,A,A,A,N,Z,Z,Z,Z,Z,Z,Z,Z,Z,N},
    {T,N,A,A,A,A,A,A,A,A,N,Z,Z,Z,Z,Z,Z,Z,Z,N,T},
    {T,T,N,A,A,A,A,A,A,A,N,Z,Z,Z,Z,Z,Z,Z,N,T,T},
    {T,T,T,N,A,A,A,A,A,A,N,Z,Z,Z,Z,Z,Z,N,T,T,T},
    {T,T,T,T,N,A,A,A,A,A,N,Z,Z,Z,Z,Z,N,T,T,T,T},
    {T,T,T,T,T,N,A,A,A,A,N,Z,Z,Z,Z,N,T,T,T,T,T},
    {T,T,T,T,T,T,N,A,A,A,N,Z,Z,Z,N,T,T,T,T,T,T},
    {T,T,T,T,T,T,T,N,N,N,N,N,N,N,T,T,T,T,T,T,T}
};*/

const int fondo[ORDEN][ORDEN]=
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

    //inicializa ttf
    if (TTF_Init() == -1)
    {
        SDL_Log("Error al inicializar SDL_ttf: %s", TTF_GetError());
        return 1;
    }

    // Cargar fuente
    TTF_Font* fuente = TTF_OpenFont("fnt/arial.ttf", 24);
    if (!fuente)
    {
        SDL_Log("No se pudo cargar fuente: %s", TTF_GetError());
        return 1;
    }


    //FUNCION JUEGO BASICO
    //pulsarSectorLuz(renderer,simon4Colores,ORDEN);

    SDL_SetRenderDrawColor(renderer, 36, 9, 66, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    //dibujarEnMenu(renderer,fondo,ORDEN,ORDEN,1,1,2);
    //dibujarEnMenu(renderer,estrella,ORDENMENU,ORDENMENU,estrellaX,estrellaY,2);




    int ejecutando=1;

    SDL_Event e;
    while (ejecutando)
    {

        while (SDL_PollEvent(&e))
        {

            if (e.type == SDL_QUIT)
                ejecutando = 0;

            for (int i = 0; i < 4; i++)
            {
                if (boton_manejo_evento(&menu_botones[i], &e))
                {
                    SDL_Log("Boton %s presionado", menu_botones[i].texto);
                    if(i == 0)
                    {

                        simon4(renderer,simon4Colores);
                    }
                    if(i == 1)
                    {
                        simon8(renderer,simon8Colores);
                    }
                    if(i == 2)
                    {

                    }
                    if (i == 3)
                    {
                        ejecutando = 0; // SALIR
                    }

                }
            }

        }


        for (int i = 0; i < 4; i++)
            boton_render(renderer, &menu_botones[i], fuente);

        SDL_RenderPresent(renderer);
    }



    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    TTF_CloseFont(fuente);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
