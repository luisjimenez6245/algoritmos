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
#include "util.h"

/*
FUNCIÓN: imprimir_arreglo(int *apt_arreglo, int n)
DESCRIPCIÓN: funcion para imprimir arreglo de enteros
RECIBE: int *apt_arreglo(el arreglo a imprimir), int n(el tamaño del arreglo)
DEVUELVE: void
OBSERVACIONES: desactivado por motivos prácticos
*/
void imprimir_arreglo(int *apt_arreglo, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		//printf("%d \n", apt_arreglo[i]);
	}
}

/*
FUNCIÓN: int obtener_n()
DESCRIPCIÓN: funcion para solicitar una n al usuario
RECIBE: void
DEVUELVE: int (el número ingresado)
OBSERVACIONES: 
*/
int obtener_n()
{
	int n;
	scanf("%d", &n);
	return n;
}

/*
FUNCIÓN: int *leer_archivo(int *apt_arreglo, int n)
DESCRIPCIÓN: funcion para solicitar una n al usuario
RECIBE:  int *apt_arreglo (el puntero al arreglo de enteros en donde se van a guardar), int n (el número n de numeros a leer)
DEVUELVE: int (el puntero al arreglo de números)
OBSERVACIONES: 
*/
int *leer_archivo(int *apt_arreglo, int n)
{
	FILE *fp = fopen("numeros10millones.txt", "r");

	apt_arreglo = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%d", (apt_arreglo + i));
	}

	fclose(fp);

	return apt_arreglo;
}

/*
FUNCIÓN: imprimir_tiempos(double utime0, double stime0, double wtime0, double utime1, double stime1, double wtime1)
DESCRIPCIÓN: funcion para imprimir los tiempos totales
RECIBE:  double utime0, double stime0, double wtime0, double utime1, double stime1, double wtime1
DEVUELVE: void
OBSERVACIONES: leer time.h para más información
*/
void imprimir_tiempos(double utime0, double stime0, double wtime0, double utime1, double stime1, double wtime1)
{
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n", stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
}