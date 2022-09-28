#include "TDAGrafo.h"
#include <iostream>
using namespace std;

TDAGrafo::TDAGrafo(){
	this->size=0;
	this->matriz=new Vertice*[0];
	for (int i=0; i<size; i++){
		matriz[i]=new Vertice[0];
	}
}

TDAGrafo::TDAGrafo(int size){
	this->size=size;
	this->matriz=new Vertice*[size];
	for (int i=0; i<size; i++){
		matriz[i]=new Vertice[size];
	}
}

int TDAGrafo::getSize(){
	return this->size;
}

Vertice** TDAGrafo::getMatriz(){
	return this->matriz;
}

void TDAGrafo::setMatriz(Vertice** matriz){
	this->matriz=matriz;
}

void TDAGrafo::setSize(int size){
	this->size=size;
}