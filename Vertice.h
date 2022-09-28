#pragma once

#ifndef VERTICE_H
#define VERTICE_H
#include <string>
using std::string;
class Vertice{
	public:
		Vertice();
		Vertice(string, string);
		string getEtiqueta();
		string getPeso();
		void setPeso(string);
		void setEtiqueta(string);
		
	protected:
		string etiqueta;
		string peso;	
};

#endif //VERTICE_H