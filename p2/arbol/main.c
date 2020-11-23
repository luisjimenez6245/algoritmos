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

ArbinOr carga_arbol_binario_busqueda(ArbinOr arbol, int *arreglo, int n);

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
   	int x = 0;
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
	
	if(estaArbinOr(arbol, x)) 
		printf("Si se encontro el elemento %d en el arbol\n", x); 
	else 
		printf("No se encontro el elemento %d en el arbol\n", x); 
       		
	uswtime(&utime1, &stime1, &wtime1);

	printf("Valor de n: %d\n", n); 	
	imprimir_tiempos(utime0, stime0, wtime0, utime1, stime1, wtime1);

	imprimir_arreglo(arreglo, n);
	printf("\n");

	destruirArbinOr(arbol); 

	return 0;
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
