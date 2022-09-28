#pragma once

#ifndef FLOYD_H
#define FLOYD_H
#include "TDAGrafo.h"

class Floyd : public TDAGrafo {
	public: 
		Floyd(int size);
		void almacenarCostos();
		void algoritmoFloyd();
	protected:
		const int nan = 9999999;
		int** costos;
};

#endif //FLOYD_H