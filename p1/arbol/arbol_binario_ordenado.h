#pragma once
#include"TipoAO.h"

struct NodoArbinOr 
{
	TipoAO info; 
	struct NodoArbinOr* izq;
	struct NodoArbinOr* der; 
}; 

typedef struct NodoArbinOr TArbinOr; 
typedef struct NodoArbinOr* ArbinOr;

//-----	Constructora -----

/* FUNCIÓN : Crea un árbol binario vacío.  
 */ 
ArbinOr inicArbinOr(void); 


//-----	Modificadoras -----

/* FUNCIÓN : Agrega un elemento a un árbol binario ordenado. 
 */ 
ArbinOr insArbinOr(ArbinOr a, TipoAO elem); 

/* FUNCIÓN : Elimina un elemento de un árbol binario ordenado.  
 */ 
ArbinOr elimArbinOr(ArbinOr a, TipoAO elem); 


//-----	Analizadora -----

/* FUNCIÓN : Informa si un elemento se encuentra en el árbol binario ordenado. 
 */
int estaArbinOr(ArbinOr a, TipoAO elem); 


//----- Analizadoras de cualquier árbol binario ---- 

ArbinOr izqArbinOr(ArbinOr a); 

ArbinOr derArbinOr(ArbinOr a); 

TipoAO raizArbinOr(ArbinOr a); 

int vacioArbinOr(ArbinOr a);


//----- Funciones de recorrido ----- 

void inordenItera(ArbinOr a);

void guardar_recorrido_inorder(ArbinOr a, int* arreglo);  


//----- Otras funciones -----
int visitar(TipoAO info);
