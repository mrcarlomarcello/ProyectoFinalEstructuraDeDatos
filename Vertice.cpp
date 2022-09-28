#include "Vertice.h"
#include <iostream>
#include <string>
using namespace std;

Vertice::Vertice(){
	this->etiqueta="";
	this->peso="";
}

Vertice::Vertice(string etiqueta, string peso){
	this->etiqueta=etiqueta;
	this->peso=peso;
}

string Vertice::getEtiqueta(){
	return this->etiqueta;
}

string Vertice::getPeso(){
	return this->peso;
}

void Vertice::setEtiqueta(string etiqueta){
	this->etiqueta=etiqueta;
}

void Vertice::setPeso(string peso){
	this->peso=peso;
}