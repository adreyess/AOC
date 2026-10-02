#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Muestras 100000
#define MAX_Sensores 20

struct Muestra {
    int Id;                   // Código autonumérico asignado a cada muestra
    int COD_Sensor;           // Codigo de cada sensor almacenado 
    int Marca_tiempo;         // Segundos transcurridos desde el inicio del muestreo hasta la lectura
    float Valor;              // valor de lectura de un sensor
};

struct Muestras* V_Muestras[MAX_Muestras]; // Vector de Punteros a estructuras 
int CONTADOR_M;  // Indica el número de muestras insertadas en el vector

//int Sensores[MAX_Sensores]; 

int Add_Muestra(struct Muestra* vector_muestras[],struct Muestra* nueva_muestra) {
    if (CONTADOR_M >= MAX_Muestras) {
        printf("No se pueden agregar más muestras: límite alcanzado.\n");
        return 0; // Límite de almacenamiento alcanzado
    }
    vector_muestras[CONTADOR_M++] = nueva_muestra;
    return 0; 
}

int Insertar_Muestra(struct Muestra* vector_muestras[], int pos, struct Muestra *nueva_muestra) {
    // Verificar si la posición es válida y si hay espacio para insertar una nueva muestra
    if (pos < 0 || pos > CONTADOR_M) {
        printf("Posición inválida para inserción.\n");
        return -1; // Error de posición inválida
    }
    if (CONTADOR_M >= MAX_Muestras) {
        printf("No se pueden agregar más muestras: límite alcanzado.\n");
        return -1; // Límite de almacenamiento alcanzado
    }

    // Desplazar muestras existentes hacia adelante para hacer espacio para la nueva muestra
    for (int i = CONTADOR_M; i > pos; i--) {
        vector_muestras[i] = vector_muestras[i - 1];
    }

    // Insertar la nueva muestra en la posición especificada
    vector_muestras[pos] = nueva_muestra;
    CONTADOR_M++; // Incrementar el contador de muestras
    return 0; // Inserción exitosa
}

int Borrar_Muestra(struct Muestra* vector_muestras[], int pos) {
    // Verificar si la posición es válida
    if (pos < 0 || pos >= CONTADOR_M) {
        printf("Posición inválida para borrado.\n");
        return -1; // Error de posición inválida
    }

    // Desplazar muestras hacia atrás para llenar el espacio de la muestra borrada
    for (int i = pos; i < CONTADOR_M - 1; i++) {
        vector_muestras[i] = vector_muestras[i + 1];
    }

    // Decrementar el contador de muestras
    CONTADOR_M--;

    // Opcionalmente, limpiar la última posición si es necesario
    memset(&vector_muestras[CONTADOR_M], 0, sizeof(struct Muestra));

    return 0; // Borrado exitoso
}


int actualizar_contadores(struct Muestra* vector_muestras[], int num_muestras, int* v_contadores) { 
    int Max=0;
    int Max_id =-1;
    for (int i = 0; i < num_muestras; i++) {
        int cod = vector_muestras[i]->COD_Sensor;
        if (cod < MAX_Sensores) {
            v_contadores[cod]++;
            if (v_contadores[cod] > Max) {
                Max=v_contadores[cod];
                Max_id=cod;
            }
        } 
    }
    return Max_id;
}

float Media_Sensor(struct Muestra* vector_muestras[], int num_muestras, int Cod_Sensor) {
    float suma = 0.0;
    int contador = 0;

    for (int i = 0; i < num_muestras; i++) {
        if (vector_muestras[i]->COD_Sensor == Cod_Sensor) {
            suma += vector_muestras[i]->Valor;
            contador++;
        }
    }
    if (contador == 0) {
        printf("No se encontraron muestras para el sensor con código %d.\n", Cod_Sensor);
        return 0.0;  // Puede optar por devolver un valor específico o manejar esta situación como un error
    }

    return suma / (float)contador;  // Retorna la media de los valores
}

int main() {
    // Crear y añadir algunas muestras
    for (int i = 0; i < 500; i++) {
        struct Muestra* m = malloc(sizeof(struct Muestra));
        if (m == NULL) {
            printf("Error de asignación de memoria.\n");
            return -1;
        }
        m->Id = i;
        m->COD_Sensor = i % MAX_Sensores; // Asignar códigos de sensor de forma cíclica
        m->Marca_tiempo = i * 100;
        m->Valor = 0.5 * i;
        int r=Add_Muestra(V_Muestras,m);
    }

    // Actualizar contadores y encontrar el sensor más usado
    int sensor_popular = actualizar_contadores(V_Muestras, CONTADOR_M, Sensores);

    // Imprimir el sensor más usado y su cuenta
    if (sensor_popular != -1) {
        printf("El sensor más utilizado es %d con %d lecturas.\n", sensor_popular, Sensores[sensor_popular]);
    }

    // Liberar la memoria asignada a las muestras
    for (int i = 0; i < CONTADOR_M; i++) {
        free(V_Muestras[i]);
    }
}