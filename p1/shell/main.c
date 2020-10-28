#include <stdio.h>
#include <stdlib.h>
#include "../util.h"

void shell(int *apt_arreglo, int n);

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

	shell(arreglo, n);

	imprimir_arreglo(arreglo, n);
	printf("\n");

	return 0;
}

void shell(int *apt_arreglo, int n)
{
	int k, b, i, temp;
	k = (n / 2);
	while (k >= 1)
	{
		b = 1;
		while (b != 0)
		{
			b = 0;
			for (i = k; i <= n - 1; i++)
			{
				if (apt_arreglo[i - k] > apt_arreglo[i])
				{
					temp = apt_arreglo[i];
					apt_arreglo[i] = apt_arreglo[i - k];
					apt_arreglo[i - k] = temp;
					b = b + 1;
				}
			}
		}
		k = (k / 2);
	}
}
