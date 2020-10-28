#pragma once
#include"TipoP.h"

struct TNodoPila 
{
	TipoP info; 
	struct TNodoPila* sig; 
}; 

typedef struct TNodoPila TPila; 
typedef struct TNodoPila* Pila; 

// ----- Constructora -----

/* FUNCIÓN : Crea una pila vacía.   
 */ 
Pila inicPila(void); 


// ----- Modificadoras ----- 

/* FUNCIÓN : Coloca sobre el tope de la pila el elemento elem. 
 */ 
void adicPila(Pila pil, TipoP elem); 

/* FUNCIÓN : Elimina el elemento que se encuentra en el tope de la pila. 
 */ 
void elimPila(Pila pil); 


// ----- Analizadoras ----- 

/* FUNCIÓN : Retorna el elemento que se encuentra en el tope de la pila.  
 */ 
TipoP infoPila(Pila pil); 

/* FUNCIÓN : Informa si la pila está vacía. 
 */
int vaciaPila(Pila pil); 

/* FUNCIÓN : Destruye la pila retornando toda la memoria ocupada. 
 */ 
void destruirPila(Pila pil); 
