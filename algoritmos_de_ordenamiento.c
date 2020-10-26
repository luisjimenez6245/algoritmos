#include"algoritmos_de_ordenamiento.h" 

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
