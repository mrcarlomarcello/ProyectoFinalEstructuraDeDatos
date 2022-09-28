#pragma once

#ifndef VERTICE_H
#define VERTICE_H
#include <string>
using std::string;
class Vertice{
	public:
		Vertice();
		Vertice(int);
		Vertice(string, int);
		string getEtiqueta();
		int getPeso();
		void setPeso(int);
		void setEtiqueta(string);
		
	protected:
		string etiqueta;
		int peso;	
};

#endif //VERTICE_H