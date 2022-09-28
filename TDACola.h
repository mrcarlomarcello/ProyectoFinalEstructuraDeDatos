#pragma once
//
// Created by dessire
// ordered by shell0
//
#ifndef TDACOLA_H
#define TDACOLA_H

#include "Object.h"

class TDACola{

    public:
        virtual void pone_en_cola(Object*)=0;//Queue
        virtual Object* saca_de_cola()=0;//Dequeue
        virtual Object* frente()=0;//peek
        virtual bool vacia()=0;
		virtual void imprime_cola()=0;
		virtual void anula()=0;

	protected:
};

#endif