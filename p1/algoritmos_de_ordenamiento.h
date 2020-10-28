#pragma once 

// TODO: ¿Documentar estos prototipos de función?  

/* FUNCIÓN: Ordena ascendentemente un arreglo de números. 
 *
 * PARÁMETROS: 
 * 	apt_arreglo	:	apuntador al arreglo de enteros a ordenar. 
 * 	n 		: 	cantidad de enteros del arreglo a ordenar. 
 *RETORNNO: 
 	void 		
 */ 

void burbuja_simple(int* apt_arreglo, int n); 

void burbuja_optimizada(int* apt_arreglo, int n); 

void insercion(int* apt_arreglo, int n);

void seleccion(int* apt_arreglo, int n);

void shell(int* apt_arreglo, int n); 
