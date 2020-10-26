#include<stdio.h> 
#include<stdlib.h> 
#include"util.h" 

void burbuja_simple(int* apt_arreglo, int n); 

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

	burbuja_simple(arreglo, n); 

	imprimir_arreglo(arreglo, n); 
	printf("\n"); 

	return 0; 
}

void burbuja_simple(int* apt_arreglo, int n)
{
	int i, j, aux; 
	for(i = 0; i <= n - 1; i++) 
		for(j = 0; j <= n - i - 2; j++) 
		{
			if(apt_arreglo[j] > apt_arreglo[j + 1]) 
			{
				aux = apt_arreglo[j]; 
				apt_arreglo[j] = apt_arreglo[j + 1]; 
				apt_arreglo[j + 1] = aux; 
			}
		}
}
