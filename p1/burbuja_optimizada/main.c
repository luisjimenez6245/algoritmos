#include <stdio.h>
#include <stdlib.h>
#include "../util.h"

void burbuja_optimizada(int *apt_arreglo, int n);

int main(int argc, const char **argv)
{
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

	burbuja_optimizada(arreglo, n);

	imprimir_arreglo(arreglo, n);
	printf("\n");

	return 0;
}

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
