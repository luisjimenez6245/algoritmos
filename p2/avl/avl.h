#pragma once 
#include"TipoAVL.h" 

#define FALSE 0
#define TRUE 1

#define IZQ 1
#define BAL 0
#define DER -1

struct NodoAVL 
{
	TipoAVL info; 
	struct NodoAVL* izq; 
	struct NodoAVL* der; 
	int balan; 
};

typedef struct NodoAVL TAVL; 
typedef struct NodoAVL* AVL; 

// ----- Constructora ----- 
/* FUNCIÓN:	Crea un árbol AVL vacío.
 */
AVL iniAVL(void); 

// ---- Auxiliares ----- 
/* Rutina para la rotación a la izquierda (no recalcula el factor de balance) */ 
AVL roteIzq(AVL a); 

/* Rutina para la rotación a la derecha (no recalcula el factor de balance) */
AVL roteDer(AVL a);

/* Rutina para la doble rotación derecha-izquierda (no recalcula el factor de balance) */ 
AVL roteDerIzq(AVL a); 

/* Rutina para la doble rotación izquierda-derecha (no recalcula el factor de balance) */ 
AVL roteIzqDer(AVL a); 

/* Rutina para balancer el subárbol derecho de un árbol AVL. Acutaliza los indicadores que lo requieran. */
AVL balanceaDer(AVL a); 

/* Rutina para balancer el subárbol izquierdo de un árbol AVL. Acutaliza los indicadores que lo requieran. */
AVL balanceaIzq(AVL a); 

/* Rutina que reibe un árbol AVL y un nodo con el elemento que se quiere agregar, y retorna funcionalmente un árbol AVL con el nuevo nodo agregado a la estructura incial. Informa, en un parámetro por referencia, si la altura del árbol resultante es mayor que la altura del árbol inicial.*/ 
AVL insertar(AVL a, struct NodoAVL* p, int* masAlto);  

// ----- Modificadoras ----
/* FUNCIÓN: 	Adiciona un elemento a árbol AVL. 
 */
AVL insAVL(AVL a, TipoAVL elem);

/* FUNCIÓN:	Elimina un elemento de un árbol AVL.
 */ 
//AVL elimAVL(AVL a, TipoAVL elem);

// ----- Analizadora ------
/* FUNCIÓN: 	Informa si un elemento se encuentra en el árbol AVL. 
 */
int estaAVL(AVL a, TipoAVL elem); 

// ----- Destructora ------
void destruirAVL(AVL a); 

