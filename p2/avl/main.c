/*
	AUTORES (C)  2020: 
		Hernández López Moises
		Herrera Merino Roxana Angélica
		Jiménez Delgado Luis Diego
	VERSIÓN: 1.0
	DESCRIPCIÓN: Implementación del algoritmo de búsqueda en un árbol AVL. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
#include "../utils/util.h"
#include "../utils/tiempo.h"

AVL carga_avl(AVL arbol, int *arreglo, int n);

/*
FUNCIÓN: main(int argc, const char **argv)
DESCRIPCIÓN: Main del programa
RECIBE: int argc (número de argumentos recibidos), const char **argv (argumentos recibidos)
DEVUELVE: int 0
OBSERVACIONES: puede recibir el número n como argumento, si no se lo recibe lo solicita en la hora de ejecución
*/


// MAIN 
int main(int argc, const char **argv)
{
	double utime0, stime0, wtime0, utime1, stime1, wtime1;	
	int i;
	int *arreglo;
	AVL arbol = iniAVL();
    
	int n = 0;	// cantidad de números
   	int x = 0;	// número a buscar 
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
	arbol = carga_avl(arbol, arreglo, n);

	uswtime(&utime0, &stime0, &wtime0);
	
	
	if(estaAVL(arbol, x)) 
		printf("SI\n"); 
	else 
		printf("NO\n"); 
    
	uswtime(&utime1, &stime1, &wtime1);

	imprimir_tiempos(utime0, stime0, wtime0, utime1, stime1, wtime1);

	imprimir_arreglo(arreglo, n);

	destruirAVL(arbol); 

	return 0;
}

/* FUNCIÓN:	carga_arbol_binario_busqueda(ArbinOr arbol, int *apt_arreglo, int n)
 * DESCRIPCIÓN: carga el arbol binario de búsqueda con los números del arreglo
 * RECIBE: 	AVL arbol (arbol binario vacío e inicializado), int *apt_arreglo, int n (total de números)
 * DEVUELVE: void. 
 * */

AVL carga_avl(AVL arbol, int *arreglo, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		arbol = insAVL(arbol, arreglo[i]);
	}

	return arbol; 
}
