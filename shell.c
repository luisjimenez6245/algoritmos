#include<stdio.h> 
#include<stdlib.h> 
#include"util.h" 

void shell(int* apt_arreglo, int n); 

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

	shell(arreglo, n); 

	imprimir_arreglo(arreglo, n); 
	printf("\n"); 

	return 0; 
}

void shell(int* apt_arreglo, int n) 
{
	int k, b, i, temp; 
	k = (n/2); 
	while(k >= 1) 
	{
		b = 1; 
		while(b != 0) 
		{
			b = 0; 
			for(i = k; i <= n - 1; i++) 
			{
				if(apt_arreglo[i - k] > apt_arreglo[i]) 
				{
					temp = apt_arreglo[i]; 
					apt_arreglo[i] = apt_arreglo[i - k]; 
					apt_arreglo[i - k] = temp; 
					b = b + 1; 
				}
			}
		}
		k = (k/2); 
	}
}
