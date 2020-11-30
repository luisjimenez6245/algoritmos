#include<stdlib.h> 
#include"avl.h" 

AVL iniAVL(void)
{
	return NULL; 
}

AVL roteIzq(AVL a) 
{
	AVL temp = a -> der; 
	a -> der = temp -> izq; 
	temp -> izq = a; 
	return temp; 
}

AVL roteDer(AVL a) 
{
	AVL temp = a -> izq; 
	a -> izq = temp -> der;
	temp -> der = a; 
	return temp; 
}

AVL roteDerIzq(AVL a) 
{
	a -> der = roteDer(a -> der); 
	return roteIzq(a); 
}

AVL roteIzqDer(AVL a) 
{
	a -> izq = roteIzq(a -> izq); 
	return roteDer(a); 
}

AVL balanceaDer(AVL a) 
{
	if(a -> der -> balan == DER) 
	{
		a -> balan = a -> der -> balan = BAL; 
		a = roteIzq(a); 
	}
	else 
	{
		switch(a -> der -> izq -> balan) 
		{
			case IZQ: 
				{
					a -> balan = BAL; 
					a -> der -> balan = DER; 
					break; 
				} 
			case BAL: 
				{
					a -> balan = a -> der -> balan = BAL; 
					break; 
				}	
			case DER: 
				{
					a -> balan = IZQ; 
					a -> der -> balan = BAL; 
					break; 
				}
		}
		a -> der -> izq -> balan = BAL; 
		a = roteDerIzq(a); 
	}
	return a; 
}

AVL balanceaIzq(AVL a) 
{
	if(a -> izq -> balan == IZQ) 
	{
		a -> balan = a -> izq -> balan = BAL; 
		a = roteDer(a); 
	}
	else 
	{
		switch(a -> izq -> der -> balan) 
		{
			case DER: 
				{
					a -> balan = BAL; 
					a -> izq -> balan = IZQ; 
					break; 
				} 
			case BAL: 
				{
					a -> balan = a -> izq -> balan = BAL; 
					break; 
				}	
			case IZQ: 
				{
					a -> balan = DER; 
					a -> izq -> balan = BAL; 
					break; 
				}
		}
		a -> izq -> der -> balan = BAL; 
		a = roteIzqDer(a); 
	}
	return a; 
}

AVL insAVL(AVL a, TipoAVL elem) 
{
	AVL p = (AVL) malloc(sizeof(TAVL)); 
	int masAlto; 
	p -> izq = p -> der = NULL; 
	p -> info = elem; 
	p -> balan = BAL; 
	return insertar(a, p, &masAlto); 
}

AVL insertar(AVL a, struct NodoAVL* p, int* masAlto) 
{
	if(a == NULL) 
	{
		*masAlto = TRUE; 
		a = p; 
	}
	else if(a -> info > p -> info) 
	{
		a -> izq = insertar(a -> izq, p, masAlto); 
		if(*masAlto) 
			switch(a -> balan) 
			{
				case IZQ: 
				{
					*masAlto = FALSE; 
					a = balanceaIzq(a); 
					break;
				}	
				case BAL:
				{	
					a -> balan = IZQ; 
					break; 
				}
				case DER: 	
				{	
					*masAlto = FALSE; 
					a -> balan = BAL; 
					break; 
				}
			}
	}
	else 
	{
		a -> der = insertar(a -> der, p, masAlto); 
		if(*masAlto) 
			switch(a -> balan) 
			{
				case IZQ: 
				{
					*masAlto = FALSE; 
					a -> balan = BAL; 
					break; 
				}
				case BAL: 
				{
					a -> balan = DER; 
					break; 
				}
				case DER: 
				{
					*masAlto = FALSE; 
					a = balanceaDer(a); 
				}
			}
	}

	return a; 
}

int estaAVL(AVL a, TipoAVL elem)
{
	while(a != NULL && a -> info != elem) 
		a = (elem < (a -> info)) ? a -> izq : a -> der; 
	return a != NULL;  
}	

void destruirAVL(AVL a)
{
	if(a != NULL) 
	{
		destruirAVL(a -> izq); 
		destruirAVL(a -> der); 
		free(a); 
	}
}	
