#include<stdio.h> 
#include<stdlib.h> 
#include"util.h" 

void seleccion(int* apt_arreglo, int n);  

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

	seleccion(arreglo, n); 

	imprimir_arreglo(arreglo, n); 
	printf("\n"); 

	return 0; 
}

void seleccion(int* apt_arreglo, int n) 
{
	int k, p, i, temp; 

	for(k = 0; k <= n - 2; k++) 
	{
		p = k; 
		for(i = k + 1; i <= n - 1; i++) 
		{
			if(apt_arreglo[i] < apt_arreglo[p]) 
				p = i; 
		}
		temp = apt_arreglo[p]; 
		apt_arreglo[p] = apt_arreglo[k]; 
		apt_arreglo[k] = temp; 
	}
}
