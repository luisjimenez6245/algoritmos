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
FUNCIÓN: int tipoValor(char caracter)
DESCRIPCIÓN: Evalula un cracter para ver que tipo de dato es.
RECIBE: char caracter (Caractér a evauluar).
DEVUELVE: int(Tipo de valor asignado).
OBSERVACIONES: Regresa 4 en caso de que el caracter sea una letra, regresa la 1 si el signo es + o -,regresa la 1 si el signo es + o -, 
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
