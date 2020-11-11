#include<stdio.h> 
#include<stdlib.h> 
#include"algoritmos_de_ordenamiento.h" 
#include"util.h" 

int main() 
{
	int opcion; 
	int n; 
	int* arreglo; 
	

	printf("\nArreglo a ordenar : ");  
	imprimir_arreglo(arreglo, n); 	
	printf("\n"); 

	printf("\n\tSeleccionar algoritmo de ordenamiento: \n\n"); 
	printf("\t1. Burbuja simple\n"); 
	printf("\t2. Burbuja optimizada\n"); 
	printf("\t3. Insercion\n"); 
	printf("\t4. Seleccion\n"); 
	printf("\t5. Shell\n"); 

	scanf("%d", &opcion);
	printf("\tSelección : "); 

	switch(opcion) 
	{
		case 1: 
			{
				printf("Burbuja simple\n"); 
				burbuja_simple(arreglo, n);
				break; 
			}
		case 2: 
			{
				printf("Burbuja optimizada\n"); 
				burbuja_optimizada(arreglo, n); 
				break; 
			}
		case 3: 
			{
				printf("Insercion\n"); 
				insercion(arreglo, n); 
				break; 
			}
		case 4: {
				printf("Seleccion\n"); 
				seleccion(arreglo, n); 
				break; 
			}
		case 5: 
			{
				printf("Shell\n"); 
				shell(arreglo, n); 
				break; 
			}
		default: 
			{
				printf("\nError en seleccion...\n"); 
				break; 
			}
	}

	printf("\n");
	printf("Arreglo ordenado : "); 
	imprimir_arreglo(arreglo, n); 
	printf("\n"); 

	return 0; 
}
