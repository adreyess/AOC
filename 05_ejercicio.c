En el siguiente código se define una estructura de datos para almacenar lecturas de distintos sensores. Consta de un vector que almacena 
las direcciones de memoria de estructuras con campos relativos a los sensores.
Se implementa a modo de ejemplo una función para añadir nuevas lecturas al vector Muestras.

#define MAX_Muestras 100000
#define MAX_Sensores 20

struct Muestra {
    int Id;                   // Código autonumérico asignado a cada muestra
    int COD_Sensor;           // Código de cada sensor almacenado 
    int Marca_tiempo;         // Segundos transcurridos desde el inicio del muestreo hasta la lectura
    float Valor;              // valor de lectura de un sensor
};

struct Muestras* V_Muestras[MAX_Muestras]; // Vector de Punteros a muestreos 
int CONTADOR_M;  // Indica el número de muestras insertadas en el vector


int Add_Muestra(struct Muestra* vector_muestras[],struct Muestra* nueva_muestra) {
    if (CONTADOR_M >= MAX_Muestras) {
        printf("No se pueden agregar más muestras: límite alcanzado.\n");
        return -1; // Límite de almacenamiento alcanzado
    }
    vector_muestras[CONTADOR_M++] = nueva_muestra;
    return 0;  //inserción exitosa
}

Se pide implementar dos funciones nuevas:
    (a)  La función Insertar_Muestra que añade una muestra nueva en una posición concreta del vector. Esta operación implica reorganizar
    el vector. Retornará -1 si hay algún tipo de error, en caso contrario 0.
       
    (b) La función Actualizar_contadores que retorna por parámetro un vector que contiene el número de medidas hechas de cada tipo
    de sensor. Ademas retornará el identificador con mas medidas realizadas.


Nota: Sólo implementar el código en C ANSI.

int Insertar_Muestra(struct Muestra* vector_muestras[], int pos, struct Muestra *nueva_muestra) 




int actualizar_contadores(struct Muestra* vector_muestras[], int num_muestras, int* v_contadores)