#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void imprimir_arreglo(int *apt_arreglo, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", apt_arreglo[i]);
}

int obtener_n()
{
	int n;
	scanf("%d", &n);
	return n;
}

int *leer_archivo(int *apt_arreglo, int n)
{
	FILE *fp = fopen("prueba.txt", "r");
	fscanf(fp, "%d", &n);
	apt_arreglo = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%d", (apt_arreglo + i));
	}

	fclose(fp);
	return apt_arreglo;
}