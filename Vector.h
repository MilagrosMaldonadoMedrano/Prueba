#ifndef VECTOR_H
#define VECTOR_H


#include<stdbool.h>
#include<stddef.h>
//si es bool el 0 es mal y el 1 bien, si hay mas opciones el cero esta bien y el resto de numeros no
#define TODO_OK 0
#define LLENO 1
#define DUPLICADO 2
#define CAP_IN 10
#define FACTOR_INCR 1.5
#define FACTOR_DECR 0.5
#define ERR_SIN_MEM 3
#define FACTOR_OCUP 0.25

typedef struct
{
    int* vec;
    size_t ce; //tipo de dato que se usa para guardar el tamanio
    size_t cap;
}
Vector;


bool vectorCrear(Vector* vec);
bool validarPos(int* pos,int ce);
void vectorDestruir(Vector* vec);
int vectorDevolverValor(Vector* vec,int posicion);
int vectorInsertarAlFinal(Vector* vec,int elem);
int vectorDevolverCantidad(Vector* vec);


#endif // VECTOR_H
