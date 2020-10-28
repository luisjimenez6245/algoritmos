#include<stdlib.h> 
#include"pila.h"

Pila inicPila(void) 
{
	Pila pil = (Pila) malloc(sizeof(TPila)); 
	pil -> sig = NULL; 
	return pil; 
}

void adicPila(Pila pil, TipoP elem) 
{
	Pila p = (Pila) malloc(sizeof(TPila));
	p -> info = elem; 
	p -> sig = pil -> sig; 
	pil -> sig = p; 	
}

void elimPila(Pila pil) 
{
	Pila p = pil -> sig; 
	pil -> sig = pil -> sig -> sig; 
	free(p); 
}

TipoP infoPila(Pila pil) 
{
	return pil -> sig -> info; 
}

int vaciaPila(Pila pil) 
{
	return pil -> sig == NULL; 
}

void destruirPila(Pila pil) 
{
	Pila p, q; 
	for(p = pil; p != NULL; )
	{
		q = p; 
		p = p -> sig; 
		free(q); 
	}
}
