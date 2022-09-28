#include "Vertice.h"
#include <iostream>
#include <string>
using namespace std;

Vertice::Vertice(){
	this->etiqueta="";
	this->peso=0;
}

Vertice::Vertice(int peso){
	this->peso=peso;
	this->etiqueta="";
}

Vertice::Vertice(string etiqueta, int peso){
	this->etiqueta=etiqueta;
	this->peso=peso;
}

string Vertice::getEtiqueta(){
	return this->etiqueta;
}

int Vertice::getPeso(){
	return this->peso;
}

void Vertice::setEtiqueta(string etiqueta){
	this->etiqueta=etiqueta;
}

void Vertice::setPeso(int peso){
	this->peso=peso;
}