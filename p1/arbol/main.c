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
#include "arbol_binario_ordenado.h"
#include "../utils/util.h"
#include "../utils/tiempo.h"

void ordena_con_arbol_binario_busqueda(ArbinOr arbol, int *arreglo, int n);

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
	int n, i;
	int *arreglo;
	ArbinOr arbol = inicArbinOr();

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

	ordena_con_arbol_binario_busqueda(arbol, arreglo, n);

	uswtime(&utime1, &stime1, &wtime1);

	printf("Valor de n: %d\n", n); 	
	imprimir_tiempos(utime0, stime0, wtime0, utime1, stime1, wtime1);

	imprimir_arreglo(arreglo, n);
	printf("\n");

	destruirArbinOr(arbol); 

	return 0;
}

/*
FUNCIÓN: ordena_con_arbol_binario_busqueda(ArbinOr arbol, int *apt_arreglo, int n)
DESCRIPCIÓN: Ordena el arreglo de número dado
RECIBE: ArbinOr arbol (arbol binario vacío e inicializado),int *apt_arreglo (arreglo a ordenar), int n (total de números)
DEVUELVE: void.
OBSERVACIONES: es la implementación del algoritmo de ordenamiento de arbol binario
*/

void ordena_con_arbol_binario_busqueda(ArbinOr arbol, int *arreglo, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		arbol = insArbinOr(arbol, arreglo[i]);
	}

	guardar_recorrido_inorder(arbol, arreglo);
}
