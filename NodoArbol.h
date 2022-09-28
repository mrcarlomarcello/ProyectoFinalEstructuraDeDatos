#pragma once

#ifndef NODOARBOL_H
#define NODOARBOL_H

#include "Object.h"

//decime que funciona
class NodoArbol : public Object
{
	public:
		NodoArbol();
		~NodoArbol();
		
		void setHijoIzquierdo(NodoArbol*);
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