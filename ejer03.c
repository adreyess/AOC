Sea V un vector de valores enteros short positivos, con un máximo de 1000 valores, siempre
delimitados por un valor negativo (-1), MAX un valor entero short positivo, P un puntero a un short
y PAR una variable de tipo int.

Codificar en lenguaje C una función que cuente el número de elementos del vector que cumplen
la condición de ser pares y menores que MAX. La función debe devolver en el parámetro PAR,
pasado por referencia, el número de elementos encontrados y en P un puntero al último valor par
encontrado. La cabecera de la función a implementar es:

void ProcesaVector( short *V, short MAX,int * PAR, short **P)