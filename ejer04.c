// gcc  -m32 -fno-pic -fno-asynchronous-unwind-tables -ftree-ter -o estructura1 estructura1.c
#include <stdio.h>
#define VECTORSIZE 100

struct elementType{
	int v[VECTORSIZE];
	struct elementType * pnext;
};

struct elementType * list = NULL;

struct elementType * addElementToList(struct elementType * list, struct elementType * newElement)
{
    struct elementType * p = list;

    if (list == NULL)
        list = newElement;
    else {
        while(p->pnext!=NULL)
            p = p->pnext;
            p->pnext = newElement;
         }
    newElement->pnext = NULL;
    return list;
}
/*
Suponiendo que los valores máximo y mínimo almacenados en los vectores son -1000 y 1000.
Realizar un procedimiento que busque el valor máximo de toda la lista.
El procedimiento deberá retornar por parámetro los punteros a los nodos dónde se encuentra y
otro puntero a la casilla del vector. El retorno de la función será dicho valor.
En NO caso de haber elementos, la salida será null para los punteros y 1001 para el valor.
Una posible cabecera puede ser:
*/
int Get_Max(struct elementType * list, struct elementType **nodo, int **p){
  
}
