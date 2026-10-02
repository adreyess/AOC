// gcc  -o file file.c
// para compilar en 32 bits 
// gcc  -m32 -o file file.c
// para ver el codigo ensamblador en 32 bits 
// gcc  -S -m32 -fno-pic -fno-asynchronous-unwind-tables -ftree-ter -o file.s file.c
// opcion -j n para usar n nucleos para acelerar la compilacion
// opcion -o n donde n es el nivel de optimizacion. por defecto 0 


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Size 1000
#define Max  500

 
int vector [Size];
int VSal[Size];


void init_vector(int *vector,int size, char V){
    srand(time(NULL));
    for (int i=0; i<size; i++)
        switch (V)
        {
        case 'R':
            vector[i]=rand()%Max;
            break;
        case 'Z':
            vector[i]=0;
            break;
        case '-':
            vector[i]=-1;
            break;
        default:
            vector[i]=(int) V ;
            break;
        }
    for (int i=size; i<Size;i++)
        vector[i]=-1;
}

int print_vector(const int *vector, int iz, int de){
if (de>Size) return 1;
 for (int i=iz; i<de ; i++){
        printf("vector[%d]= %d\n",i,*vector);
        vector++;
 }
return 0;
}

/* guardar en VSal los elementos de vector tales que:
    El elmento anterior y posterior son respectivamente menor y mayor que el evaluado.
    Usar para ello gramatica de punteros.
*/#define Size 1000
void cargar_adyacentes( const int *posv, int *vsal,int size){
    posv++;
    for (int i=1; i<size-1; i++){
        if (*(posv-1)<*posv && *(posv+1)>*posv){
            *vsal=*posv;
            printf("encontrado en %i: %d\n",i,*posv);
            vsal++;
        }
    posv++;
    }

}

/* guardar en Vsal progresivamente la suma de los n elementos siguientes
   en el vector de entrada tomados de k en k .
Usar para ello gramática de punteros.
*/

void suma_vector_n(int *posv,int *vsal,int n, int k, int size){

    int * posfinciclo=posv+n;
    int * posfin=posv+size;
    while (posfinciclo<posfin)
    {
        if (posv > posfinciclo){
            posv=posfinciclo;
            posfinciclo=posv+n;
            vsal++;
            continue;
        } 
        *vsal+=*posv;
        posv+=k;
    }
}


void main(){
    init_vector(vector,1000,'R');
    init_vector(VSal,1000,'-');
    suma_vector_n(vector,VSal,20,1,Size);
    print_vector(VSal,0,1000);
}