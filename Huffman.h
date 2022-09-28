#pragma once
//
// Created by shello on 09-27-22.
//

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "TDAArbol.h"
#include "LinkedList.h"
#include "Simbolo.h"
#include "NodoArbol.h"

class Huffman : public  TDAArbol{
    public:
        Huffman();
        virtual int contarCaracteres(string);
        virtual bool crearHojas(string);
        virtual void imprimirHojas();
        virtual int getSize();
        virtual NodoArbol* creaArbol();

    private:
        string frase;
        LinkedList* hojasHuffman;
        int size;
        int maxFreq;
};


#endif //HUFFMAN_H
