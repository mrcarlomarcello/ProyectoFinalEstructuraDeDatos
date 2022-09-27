#include "Nodo.h"

//#define NULL 0

Nodo::Nodo()
{
	siguiente = NULL;
	item = NULL;
	anterior = NULL;
	 
}

Nodo::~Nodo()
{
	if(siguiente)
		delete siguiente;
		
	if(item)
		delete item;
}

void Nodo::setSiguiente (Nodo* newSiguiente){
	siguiente = newSiguiente;
}

void Nodo::setAnterior(Nodo* newAnterior){
	anterior = newAnterior;
}

void Nodo::setItem(Object* itemIngresado){
	item = itemIngresado;
}

Object* Nodo::getItem(){
	return item;
}

Nodo* Nodo::getSiguiente(){
	return siguiente;
}

Nodo* Nodo:: getAnterior(){
	return anterior;
}
