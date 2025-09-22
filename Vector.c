#include "Vector.h"
#include<stdio.h>
#include<stdlib.h>



bool redimensionarVector(Vector* vector, float factor);
bool redimensionarVector(Vector* vector, float factor)
{
    size_t nuevaCap = vector->cap * factor;

    if(nuevaCap < CAP_IN)
    {
        return true;
    }

    int* nuevoVec = realloc(vector->vec, nuevaCap * sizeof(int));

    if(!nuevoVec)
    {
        return false;
    }

    //printf("Redimensión de %lld a %lld\n", vector->cap, nuevaCap);

    vector->cap = nuevaCap;
    vector->vec = nuevoVec;

    return true;
}



bool vectorCrear(Vector* vector)
{
    vector->ce=0;
    vector->cap=CAP_IN;
    vector->vec=malloc(CAP_IN*sizeof(int));

    return vector->vec!=NULL;


}

bool validarPos(int* pos,int ce)
{
    if(*pos>0 && *pos<=ce)
    {
        return true;
    }
    return false;
}

int vectorDevolverValor(Vector* vec,int posicion)
{
    return *(vec->vec+posicion);
}

int vectorInsertarAlFinal(Vector* vec,int elem)
{

    if(vec->ce == vec->cap)
    {
        if(!redimensionarVector(vec,FACTOR_INCR))
            return ERR_SIN_MEM;
    }

    int *p=vec->vec + vec->ce;
    *p=elem;
    vec->ce++;
    return TODO_OK;

}

void vectorDestruir(Vector* vec)
{
    vec->cap=0;
    vec->ce=0;

    free(vec->vec);
    vec->vec=NULL;
}




