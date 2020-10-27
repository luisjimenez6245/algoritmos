#include<stdio.h> 
#include<stdlib.h> 
#include"arbol_binario_ordenado.h" 
#include"util.h"

void ordena_con_arbol_binario_busqueda(int* arreglo, int n) 
{
	int i; 
	ArbinOr arbol = inicArbinOr(); 

	for(i = 0; i < n; i++) 
	{
		arbol = insArbinOr(arbol, arreglo[i]); 
	}

	guardar_recorrido_inorder(arbol, arreglo); 
}

int main() 
{
	int n, i; 
       	int* arreglo; 	
	
	scanf("%d", &n); 
	arreglo = (int*) malloc(n * sizeof(int)); 

	for(i = 0; i < n; i++) 
		scanf("%d", (arreglo + i)); 

	imprimir_arreglo(arreglo, n); 
	printf("\n"); 
	
	ordena_con_arbol_binario_busqueda(arreglo, n); 

	imprimir_arreglo(arreglo, n); 
	printf("\n"); 

	return 0; 
}
