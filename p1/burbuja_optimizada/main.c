/*
	AUTORES (C)  2020: 
		Hernández López Moises
		Herrera Merino Roxana Angélica
		Jiménez Delgado Luis Diego
	VERSIÓN: 1.0
	DESCRIPCIÓN: Implementación del algoritmo burbuja optimizado
*/

#include <stdio.h>
#include <stdlib.h>
#include "../utils/util.h"
#include "../utils/tiempo.h"

void burbuja_optimizada(int *apt_arreglo, int n);

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

	burbuja_optimizada(arreglo, n);

	uswtime(&utime1, &stime1, &wtime1);
	imprimir_tiempos(utime0, stime0, wtime0, utime1, stime1, wtime1);

	imprimir_arreglo(arreglo, n);
	printf("\n");

	return 0;
}

/*
FUNCIÓN: burbuja_optimizada(int *apt_arreglo, int n)
DESCRIPCIÓN: Ordena el arreglo de número dado
RECIBE: int *apt_arreglo (arreglo a ordenar), int n (total de números)
DEVUELVE: void.
OBSERVACIONES: es la implementación del algoritmo de ordenamiento burbuja optimizado
*/
void burbuja_optimizada(int *apt_arreglo, int n)
{
	int cambios = 1;
	int i = 0;
	int j, aux;

	while ((i < n - 1) && cambios)
	{
		cambios = 0;
		for (j = 0; j <= (n - 2) - i; j++)
		{
			if (apt_arreglo[j] > apt_arreglo[j + 1])
			{
				aux = apt_arreglo[j];
				apt_arreglo[j] = apt_arreglo[j + 1];
				apt_arreglo[j + 1] = aux;
				cambios = 1;
			}
		}
		i = i + 1;
	}
}
