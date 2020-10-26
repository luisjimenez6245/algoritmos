#include<stdio.h> 
#include<stdlib.h> 
#include"util.h" 

void burbuja_optimizada(int* apt_arreglo, int n);  

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

	burbuja_optimizada(arreglo, n); 

	imprimir_arreglo(arreglo, n); 
	printf("\n"); 

	return 0; 
}

void burbuja_optimizada(int* apt_arreglo, int n) 
{
	int cambios = 1; 
       	int i = 0; 
	int j, aux;  

	while((i < n - 1) && cambios) 
	{
		cambios = 0; 
		for(j = 0; j <= (n - 2) - i; j++) 
		{
			if(apt_arreglo[j] > apt_arreglo[j + 1])  
			{
				aux = apt_arreglo[j]; 
				apt_arreglo[j] = apt_arreglo[j + 1]; 
				apt_arreglo[j + 1] = aux;  
				cambios = 1; 
			}
		}
		i = i + 1; 
	}	
}
