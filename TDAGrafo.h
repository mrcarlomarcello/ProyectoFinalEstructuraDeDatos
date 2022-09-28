#pragma once

#ifndef TDAGRAFO_H
#define TDAGRAFO_H

#include "Vertice.h"



class TDAGrafo{
	public:
		TDAGrafo();
		TDAGrafo(int);
		
		int getSize();
		Vertice** getMatriz();
		void setSize(int);
		void setMatriz(Vertice**);

	protected:
		int size;
		Vertice** matriz;
};

#endif //TDAGRAFO_H