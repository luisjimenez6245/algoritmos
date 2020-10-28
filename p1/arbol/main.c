#include <stdio.h>
#include <stdlib.h>
#include "arbol_binario_ordenado.h"
#include "../util.h"

void ordena_con_arbol_binario_busqueda(int *arreglo, int n)
{
	int i;
	ArbinOr arbol = inicArbinOr();

	for (i = 0; i < n; i++)
	{
		arbol = insArbinOr(arbol, arreglo[i]);
	}

	guardar_recorrido_inorder(arbol, arreglo);
}

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

	ordena_con_arbol_binario_busqueda(arreglo, n);

	imprimir_arreglo(arreglo, n);
	printf("\n");

	return 0;
}
