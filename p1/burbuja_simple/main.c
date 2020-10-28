#include <stdio.h>
#include <stdlib.h>
#include "../utils/util.h"
#include "../utils/tiempo.h"

void burbuja_simple(int *apt_arreglo, int n);

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

	burbuja_simple(arreglo, n);

	uswtime(&utime1, &stime1, &wtime1);
	imprimir_tiempos(utime0, stime0, wtime0, utime1, stime1, wtime1);

	imprimir_arreglo(arreglo, n);
	printf("\n");

	return 0;
}

void burbuja_simple(int *apt_arreglo, int n)
{
	int i, j, aux;
	for (i = 0; i <= n - 1; i++)
		for (j = 0; j <= n - i - 2; j++)
		{
			if (apt_arreglo[j] > apt_arreglo[j + 1])
			{
				aux = apt_arreglo[j];
				apt_arreglo[j] = apt_arreglo[j + 1];
				apt_arreglo[j + 1] = aux;
			}
		}
}
