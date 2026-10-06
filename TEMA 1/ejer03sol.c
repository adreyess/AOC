Sea V un vector de valores enteros short positivos, con un máximo de 1000 valores, siempre
delimitados por un valor negativo (-1), MAX un valor entero short positivo, P un puntero a un short
y PAR una variable de tipo int.

Codificar en lenguaje C una función que cuente el número de elementos del vector que cumplen
la condición de ser pares y menores que MAX. La función debe devolver en el parámetro PAR,
pasado por referencia, el número de elementos encontrados y en P un puntero al último valor par
encontrado. La cabecera de la función a implementar es:

#include <stdio.h>

void ProcesaVector(short *V, short MAX, int *PAR, short **P) {
    *PAR = 0; // Inicializamos el contador de números pares menores que MAX
    *P = NULL; // Inicializamos el puntero al último valor par encontrado

    for (int i = 0; V[i] != -1 && i < 1000; i++) {
        if (V[i] % 2 == 0 && V[i] < MAX) {
            (*PAR)++; // Incrementamos el contador
            *P = &V[i]; // Actualizamos el puntero al último valor par encontrado
        }
    }
}

int main() {
    short V[1001] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, -1}; // Ejemplo de vector
    short MAX = 15;
    int PAR;
    short *P;

    ProcesaVector(V, MAX, &PAR, &P);

    printf("Número de elementos pares menores que %d: %d\n", MAX, PAR);
    if (P) {
        printf("Puntero al último valor par encontrado: %d\n", *P);
    } else {
        printf("No se encontró ningún valor par menor que %d\n", MAX);
    }

    return 0;
}

Esta función recorre el vector V hasta encontrar el valor -1 o hasta haber procesado 1000 valores. Durante el recorrido, verifica si cada valor es par y menor que MAX. Si es así, incrementa el contador PAR y actualiza el puntero P para que apunte al último valor par encontrado.

