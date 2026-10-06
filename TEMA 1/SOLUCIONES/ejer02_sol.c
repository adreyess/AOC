

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char cadena[100];  // vector estático de caracteres
    struct Node* next;
} Node;

int esPalindromo(char* str) {
    int l = 0;
    int h = strlen(str) - 1;

    while (h > l) {
        if (str[l++] != str[h--]) {
            return 0;
        }
    }
    return 1;
}

void agregarPalindromos(Node* text, char **salida) {
    Node* current = text;
    int i = 0;

    while (current != NULL) {
        if (esPalindromo(current->cadena)) {
            salida[i++] = current->cadena;
        }
        current = current->next;
    }
    salida[i] = NULL;  // Marcar el final de las cadenas en salida
}

int main() {
    // Construir la lista enlazada text
    Node* text = malloc(sizeof(Node));
    strncpy(text->cadena, "anilina", 100);
    text->next = malloc(sizeof(Node));
    strncpy(text->next->cadena, "radar", 100);
    text->next->next = malloc(sizeof(Node));
    strncpy(text->next->next->cadena, "hola", 100);
    text->next->next->next = malloc(sizeof(Node));
    strncpy(text->next->next->next->cadena, "reconocer", 100);
    text->next->next->next->next = malloc(sizeof(Node));
    strncpy(text->next->next->next->next->cadena, "adios", 100);
    text->next->next->next->next->next = malloc(sizeof(Node));
    strncpy(text->next->next->next->next->next->cadena, "somos", 100);
    text->next->next->next->next->next->next = NULL;

    char *salida[7] = { NULL };

    agregarPalindromos(text, salida);

    printf("Palindromos en el texto: \n");
    for (int i = 0; salida[i] != NULL; i++) {
        printf("%s\n", salida[i]);
    }

    // Liberar la memoria
    while (text != NULL) {
        Node* next = text->next;
        free(text);
        text = next;
    }

    return 0;
}


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
