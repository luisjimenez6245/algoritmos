#include<stdio.h> 
#include<stdlib.h> 
#include"util.h"

void insercion(int* apt_arreglo, int n);  

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

	insercion(arreglo, n); 

	imprimir_arreglo(arreglo, n); 
	printf("\n"); 

	return 0; 
}

void insercion(int* apt_arreglo, int n) 
{
	int i, j, temp; 
	for(i = 0; i <= n - 1; i++) 
	{
		j = i; 
		temp = apt_arreglo[i]; 
		while((j > 0) && (temp < apt_arreglo[j - 1])) 
		{
			apt_arreglo[j] = apt_arreglo[j - 1]; 
			j--; 
		}
		apt_arreglo[j] = temp; 
	}
}
