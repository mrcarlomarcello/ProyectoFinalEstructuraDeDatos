#pragma once

#ifndef NODOARBOL_H
#define NODOARBOL_H

#include "Object.h"

class NodoArbol
{
	public:
		NodoArbol();
		~NodoArbol();
		
		void setHijoIzquierdo*);
		void setHijoDerecho(NodoArbol*);
		void setItem(Object*);
		Object* getItem();
		NodoArbol* getHijoIzquierdo();
		NodoArbol* getHijoDerecho();
		
		//TO DO: Hacer gets/sets
		
	protected:
		NodoArbol* hijoIzquierdo;
		NodoArbol* hijoDerecho;
        Object* item;
};

#endif //NODOARBOL_H