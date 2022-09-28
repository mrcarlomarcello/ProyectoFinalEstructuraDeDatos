#ifndef NODO_H
#define NODO_H

#include "Object.h"

class Nodo
{
	public:
		Nodo();
		~Nodo();
		
		void setSiguiente(Nodo*);
		void setAnterior(Nodo*);
		void setItem(Object*);
		Object* getItem();
		Nodo* getSiguiente();
		Nodo* getAnterior();

	protected:
		Nodo* siguiente;
		Nodo* anterior;
        Object* item;
};

#endif