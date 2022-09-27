#include "NodoArbol.h"

//#define NULL 0

NodoArbol::NodoArbol()
{
	this->hijoIzquierdo = NULL;
    this->hijoDerecho = NULL;
	this->item = NULL;
	 
}

NodoArbol::~NodoArbol()
{
	if(hijoIzquierdo)
		delete hijoIzquierdo;

    if(hijoDerecho)
        delete hijoDerecho;
		
	if(item)
		delete item;
}

void NodoArbol::setHijoIzquierdo (NodoArbol* newIzquierdo){
	this->hijoIzquierdo = newIzquierdo;
}

void NodoArbol::setHijoDerecho(NodoArbol* newDerecho){
	this->hijoDerecho = newDerecho;
}

void NodoArbol::setItem(Object* itemIngresado){
	this->item = itemIngresado;
}

Object* NodoArbol::getItem(){
	return item;
}

NodoArbol* NodoArbol::getHijoIzquierdo(){
	return this->hijoIzquierdo;
}

NodoArbol* NodoArbol::getHijoDerecho(){
	return this->hijoDerecho;
}
