// La siguiente definición en C permite construir una lista enlazada en la que cada nodo contiene un vector de enteros de MAX elementos y un valor entero Num_Parity:

#define MAX 50

typedef struct Node {
    int VEC[MAX];       
    int Num_Parity;       
    struct Node *next;    
} Node;
struct elementType *list = NULL;

// Tenemos una función que cuenta los bits activos de un número en su representación binaria:

int count_ones(int num) {
    int count = 0;
    while (num) {
        count += num & 1;  
        num >>= 1;         
    }
    return count;
}

/*
Suponiendo que head es un puntero a una lista enlazada terminada en NULL, definir una función que recorra la lista completa y por cada nodo almacene en el campo Num_parity el número de valores del vector VEC que tienen  paridad PAR. La paridad PAR de un número es True si el número de unos en su representación binaria es par. 
Además debe retornar un puntero  al primer nodo con menos elementos con paridad PAR de la lista.
Usar la siguiente cabecera para la función:

Node* calculate_parity_and_find_min(Node *head) 
*/
