/*
	AUTORES (C)  2020: 
		Hernández López Moises
		Herrera Merino Roxana Angélica
		Jiménez Delgado Luis Diego
	VERSIÓN: 1.0
	DESCRIPCIÓN: Implementación del algoritmo arbol binario
*/

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>

#include "arbol_binario_ordenado.h"
#include "../utils/util.h"
#include "../utils/tiempo.h"

ArbinOr carga_arbol_binario_busqueda(ArbinOr arbol, int *arreglo, int n);
void busqueda(ArbinOr a);

typedef struct informacion
{
	ArbinOr arbol;
} informacion;

int x = 0;
int posicion = 0;

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
	int i;
	int *arreglo;

	ArbinOr arbol = inicArbinOr();

	int n = 0;
	if (argc >= 2)
	{
		n = atoi(argv[1]);
		if (argc > 2)
		{
			x = atoi(argv[2]);
		}
		else
		{
			x = obtener_n();
		}
	}
	else
	{
		n = obtener_n();
		x = obtener_n();
	}

	arreglo = leer_archivo(arreglo, n);
	arbol = carga_arbol_binario_busqueda(arbol, arreglo, n);

	uswtime(&utime0, &stime0, &wtime0);
	busqueda(arbol);
	uswtime(&utime1, &stime1, &wtime1);

	if (posicion != -1)
		printf("Si se encontro el elemento %d en el arbol\n", x);
	else
		printf("No se encontro el elemento %d en el arbol\n", x);

	printf("Valor de n: %d\n", n);
	imprimir_tiempos(utime0, stime0, wtime0, utime1, stime1, wtime1);

	imprimir_arreglo(arreglo, n);
	printf("\n");

	destruirArbinOr(arbol);

	return 0;
}

void busqueda_arbol(ArbinOr a, TipoAO elem)
{
	while (a != NULL && (a->info) != elem)
	{
		a = (elem < (a->info)) ? a->izq : a->der;
		if (posicion != -1)
		{
			break;
		}
	}
	if (a != NULL)
	{
		posicion = 1;
	}
}

void *thread_process(void *datos)
{
	informacion *info = datos;
	busqueda_arbol(info->arbol, x);
	pthread_exit(0);
}

void busqueda(ArbinOr a)
{
	pthread_t thread_izq;
	pthread_t thread_der;
	informacion *info_izq = malloc(sizeof(info_izq));
	informacion *info_der = malloc(sizeof(info_der));

	info_izq->arbol = a->izq;
	info_der->arbol = a->der;

	int status, i, *exit_code, aux;

	if (a->info == x)
	{
		posicion = 1;
		return;
	}

	status = pthread_create(&thread_izq, NULL, thread_process, info_izq);
	if (status)
	{
		printf("\nError en thread %i\n", status);
		exit(-1);
	}

	status = pthread_create(&thread_der, NULL, thread_process, info_der);
	if (status)
	{
		printf("\nError en thread %i\n", status);
		exit(-1);
	}
	pthread_join(thread_izq, (void **)&exit_code);
	pthread_join(thread_der, (void **)&exit_code);
}

/*
FUNCIÓN: carga_arbol_binario_busqueda(ArbinOr arbol, int *apt_arreglo, int n)
DESCRIPCIÓN: carga el arbol binario de búsqueda con los números del arreglo
RECIBE: ArbinOr arbol (arbol binario vacío e inicializado),int *apt_arreglo, int n (total de números)
DEVUELVE: void.
*/

ArbinOr carga_arbol_binario_busqueda(ArbinOr arbol, int *arreglo, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		arbol = insArbinOr(arbol, arreglo[i]);
	}

	return arbol;
}
