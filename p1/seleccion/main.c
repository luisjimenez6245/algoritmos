#include <stdio.h>
#include <stdlib.h>
#include "../utils/util.h"
#include "../utils/tiempo.h"

void seleccion(int *apt_arreglo, int n);

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

	seleccion(arreglo, n);

	uswtime(&utime1, &stime1, &wtime1);
	imprimir_tiempos(utime0, stime0, wtime0, utime1, stime1, wtime1);

	imprimir_arreglo(arreglo, n);
	printf("\n");

	return 0;
}

void seleccion(int *apt_arreglo, int n)
{
	int k, p, i, temp;

	for (k = 0; k <= n - 2; k++)
	{
		p = k;
		for (i = k + 1; i <= n - 1; i++)
		{
			if (apt_arreglo[i] < apt_arreglo[p])
				p = i;
		}
		temp = apt_arreglo[p];
		apt_arreglo[p] = apt_arreglo[k];
		apt_arreglo[k] = temp;
	}
}
