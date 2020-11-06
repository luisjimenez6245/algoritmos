/*
	AUTORES (C)  2020: 
		Hernández López Moises
		Herrera Merino Roxana Angélica
		Jiménez Delgado Luis Diego
	VERSIÓN: 1.0
	DESCRIPCIÓN: Implementación del algoritmo de ordenamiento insercion
*/


#include <stdio.h>
#include <stdlib.h>
#include "../utils/util.h"
#include "../utils/tiempo.h"

void insercion(int *apt_arreglo, int n);

/*
FUNCIÓN: main(int argc, const char **argv)
DESCRIPCIÓN: Main del programa
RECIBE: int argc (número de argumentos recibidos), const char **argv (argumentos recibidos)
DEVUELVE: int 0
OBSERVACIONES: puede recibir el número n como argumento, si no se lo recibe lo solicita en la hora de ejecución
*/
int main(int argc, const char **argv)
{
	double utime0, stime0, wtime0, utime1, stime1, wtime1;
	int n, i;
	int *arreglo;

	if (argc == 2)
	{
		n = atoi(argv[1]);
	}
	else
	{
		n = obtener_n();
	}

	arreglo = leer_archivo(arreglo, n);
	uswtime(&utime0, &stime0, &wtime0);

	insercion(arreglo, n);

	uswtime(&utime1, &stime1, &wtime1);
	imprimir_tiempos(utime0, stime0, wtime0, utime1, stime1, wtime1);

	imprimir_arreglo(arreglo, n);
	printf("\n");

	return 0;
}

/*
FUNCIÓN: insercion(int *apt_arreglo, int n)
DESCRIPCIÓN: Ordena el arreglo de número dado
RECIBE: int *apt_arreglo (arreglo a ordenar), int n (total de números)
DEVUELVE: void.
OBSERVACIONES: es la implementación del algoritmo de ordenamiento de insercion
*/
void insercion(int *apt_arreglo, int n)
{
	int i, j, temp;
	for (i = 0; i <= n - 1; i++)
	{
		j = i;
		temp = apt_arreglo[i];
		while ((j > 0) && (temp < apt_arreglo[j - 1]))
		{
			apt_arreglo[j] = apt_arreglo[j - 1];
			j--;
		}
		apt_arreglo[j] = temp;
	}
}
