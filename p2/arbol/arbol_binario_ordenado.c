#include<stdio.h> 
#include<stdlib.h> 
#include"arbol_binario_ordenado.h"
#include"pila.h"

ArbinOr inicArbinOr(void) 
{
	return NULL;  
}

ArbinOr insArbinOr(ArbinOr a, TipoAO elem) 
{
	ArbinOr resp = a; 
	ArbinOr aux = (ArbinOr) malloc(sizeof(TArbinOr)); 

	aux -> info = elem; 
	aux -> izq = aux -> der = NULL; 
	
	if(a == NULL) 
		return aux; 

	while((elem < (a -> info) && a -> izq != NULL) || (elem > (a -> info) && a -> der != NULL))
	{
		a = (elem < (a -> info)) ? a -> izq : a -> der;
	}	
	
	if(elem < (a -> info)) 
		a -> izq = aux; 
	else 
		a -> der = aux; 
	return resp; 
}

ArbinOr elimArbinOr(ArbinOr a, TipoAO elem)
{
	ArbinOr padre1, padre2, a1, a2; 
	padre1 = NULL;
       	a1 = a; 

	while(a1 != NULL) 
	{
		while(a1 -> info != elem) 
		{
			padre1 = a1; 
			a1 = (elem < a1 -> info) ? a1 -> izq : a1 -> der; 
		}
		if(a1 -> izq == NULL && a1 -> der == NULL) 
		{
			if(padre1 == NULL) 
				a = NULL; 
			else if(padre1 -> izq == a1) 
				padre1 -> izq = NULL; 
			else 
				padre1 -> der = NULL; 
			break; 
		}
		else if(a1 -> izq == NULL) 
		{
			/* solo tiene hijo derecho */
			if(padre1 == NULL) 
				a = a -> der; 
			else if(padre1 -> izq == a1) 
				padre1 -> izq = a1 -> der; 
			else 
				padre1 -> der = a1 -> der; 
			break; 
		}
		else if(a1 -> der == NULL) 
		{
			/* solo tiene hijo izquierdo */ 
			if(padre1 == NULL) 
				a = a -> izq; 
			else if(padre1 -> izq == a1) 
				padre1 -> izq = a1 -> izq; 
			else 
				padre1 -> der = a1 -> izq; 
			break; 
		}
		else 
		{
			/* tiene ambos hijos */ 
			for(a2 = a1 -> der, padre2 = a1; a2 -> izq != NULL; padre2 = a2, a2 = a2 -> izq); 
			a1 -> info = a2 -> info; 
			elem = a2 -> info; 
			padre1 = padre2; 
			a1 = a2; 
		}
	}	
	free(a1); 
	return a; 
}


int estaArbinOr(ArbinOr a, TipoAO elem) 
{
	while(a != NULL && (a -> info) != elem)
		a = (elem < (a -> info))  ? a -> izq : a -> der; 
	return a!= NULL; 
}

ArbinOr izqArbinOr(ArbinOr a)
{
	return a -> izq; 
}

ArbinOr derArbinOr(ArbinOr a) 
{
	return a -> der; 
}

TipoAO raizArbinOr(ArbinOr a) 
{
	return a -> info; 
}

int vacioArbinOr(ArbinOr a) 
{
	return a == NULL; 
}

void destruirArbinOr(ArbinOr a)
{
	if(a != NULL) 
	{
		destruirArbinOr(a -> izq); 
		destruirArbinOr(a -> der); 
		free(a); 
	}
}

void inordenItera(ArbinOr a) 
{
	Pila pil; 
	ArbinOr arb; 
	if(!vacioArbinOr(a))
	{
		arb = izqArbinOr(a); 
		pil = inicPila(); 
		adicPila(pil, a); 
		while(!vacioArbinOr(arb) || !vaciaPila(pil)) 
		{
			if(!vacioArbinOr(arb)) 
			{
				adicPila(pil, arb); 
				arb = izqArbinOr(arb); 
			}
			else 
			{
				arb = infoPila(pil); 
				elimPila(pil); 
				visitar(raizArbinOr(arb)); 
				arb = derArbinOr(arb); 
			}

		}	
	}
}


void guardar_recorrido_inorder(ArbinOr a, int* arreglo)  
{
	int i = 0; 
	Pila pil; 
	ArbinOr arb; 
	if(!vacioArbinOr(a))
	{
		arb = izqArbinOr(a); 
		pil = inicPila(); 
		adicPila(pil, a); 
		while(!vacioArbinOr(arb) || !vaciaPila(pil)) 
		{
			if(!vacioArbinOr(arb)) 
			{
				adicPila(pil, arb); 
				arb = izqArbinOr(arb); 
			}
			else 
			{
				arb = infoPila(pil); 
				elimPila(pil); 
				arreglo[i] = visitar(raizArbinOr(arb));
			       	i++; 	
				arb = derArbinOr(arb); 
			}

		}	
	}
}

int visitar(TipoAO info) 
{
	return info;  
}
