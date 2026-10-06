// 
Contamos con un vector "Data" de 5 elementos puntero a entero.
Estos elementos apuntan  a vectores con un máximo de 100 elementos positivos ordenados en orden ascendente
y delimitados por un valor negativo (-1).
Contamos con otro vector "Result" con 500 enteros inicializados a valor -1.

Realizar un algoritmo escrito en C que almacene en Result todos los elementos de Data ordenados de menor a mayor.

#define NVEC 5

int Menor(int *Data[NVEC]) {
    int v = -1;
    int j = -1;                          /* -1: aún sin candidato */

    for (int i = 0; i < NVEC; i++) {
        if (*Data[i] != -1) {
            if (j == -1 || *Data[i] < v) {
                v = *Data[i];
                j = i;
            }
        }
    }

    if (j != -1)
        Data[j]++;                       /* consumimos el elemento */

    return v;                            /* -1 si todo agotado */
}

void OrdenarVector(int *Data[NVEC], int *Result) {
    int value;
    int *p = Result;

    do {
        value = Menor(Data);
        if (value != -1) {
            *p = value;
            p++;
        }
    } while (value != -1);               
}

int main(void) {
    int a[] = {1, 4, 9, -1};
    int b[] = {2, 3, 10, -1};
    int c[] = {-1};
    int d[] = {5, 6, 7, 8, -1};
    int e[] = {0, 11, -1};
    int *Data[5] = {a, b, c, d, e};
    int Result[500];
    for (int i = 0; i < 500; i++) Result[i] = -1;

    OrdenarVector(Data, Result);

    for (int i = 0; Result[i] != -1; i++)
        printf("%d ", Result[i]);
    printf("\n");   /* 0 1 2 3 4 5 6 7 8 9 10 11 */
    return 0;
}