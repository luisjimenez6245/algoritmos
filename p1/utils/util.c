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

	apt_arreglo = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%d", (apt_arreglo + i));
	}

	fclose(fp);
	
	return apt_arreglo;
}

void imprimir_tiempos(double utime0, double stime0, double wtime0, double utime1, double stime1, double wtime1)
{
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
}