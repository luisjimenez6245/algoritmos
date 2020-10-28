#include <stdio.h>
#include <stdlib.h>
#include"../util.h" 

void insercion(int *apt_arreglo, int n);

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

	insercion(arreglo, n);

	imprimir_arreglo(arreglo, n);
	printf("\n");

	return 0;
}

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
