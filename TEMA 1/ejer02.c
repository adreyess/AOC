
Se tiene una lista enlazada `Node`, donde cada nodo contiene un vector estático de caracteres `cadena` y un puntero al siguiente nodo `next`. Cada `cadena` es una secuencia de caracteres terminada en '\0'. La lista enlazada puede contener cualquier número de nodos.

Se necesita encontrar todas las cadenas que son palíndromos dentro de la lista y almacenar los punteros a estas cadenas en un vector proporcionado.

Para este propósito, se deben implementar las siguientes dos funciones:


typedef struct Node {
    char cadena[100];  // vector estático de caracteres
    struct Node* next;
} Node;

int esPalindromo(char* str) 
/*
Esta función toma una cadena de caracteres y devuelve 1 si la cadena es un palíndromo y 0 en caso contrario. 
Una cadena es un palíndromo si se lee igual de adelante hacia atrás y de atrás hacia adelante.
Se puede usar la funcion strlen() para determinar el tamaño de una cadena
*/


void agregarPalindromos(Node* text, char **salida) 
/*
Esta función toma un puntero al primer nodo de la lista enlazada y un vector de punteros a caracteres.
Debe recorrer la lista y para cada cadena que es un palíndromo (determinado por la función `esPalindromo`), debe agregar el puntero a esta cadena al vector `salida`. 
El vector `salida` está inicializado con todos los elementos en NULL y se garantiza que tiene suficiente espacio para todas las cadenas palindrómicas. 
Al final de la función, el último elemento no-NULL en `salida` debe ser seguido por un NULL para indicar el final de los punteros a las cadenas palindrómicas.

*/
