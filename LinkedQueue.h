#pragma once
//
// Created by dessire on 09-18-22
// ordered by shell0
//

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "TDACola.h"
#include "Nodo.h"

class LinkedQueue : public TDACola
{
public:
    LinkedQueue();
    ~LinkedQueue();

    virtual void pone_en_cola(Object*);//Queue
    virtual Object* saca_de_cola();//Dequeue
    virtual Object* frente();
    virtual bool vacia();
    virtual void imprime_cola();
    virtual void anula();

protected:
    Nodo* inicio;
    Nodo* final;
};

#endif
