/*
	AUTORES (C)  2020: 
		Hernández López Moises
		Herrera Merino Roxana Angélica
		Jiménez Delgado Luis Diego
	VERSIÓN: 1.0
	DESCRIPCIÓN: Implementación del algoritmo burbuja optimizado
*/

#include <stdio.h>

void imprimir_arreglo(int *apt_arreglo, int n);

int obtener_n();

int *leer_archivo(int *apt_arreglo, int n);

void imprimir_tiempos(double utime0, double stime0, double wtime0, double utime1, double stime1, double wtime1);