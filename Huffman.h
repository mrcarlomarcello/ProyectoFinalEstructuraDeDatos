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
#include "LinkedQueue.h"

#include <string>
using std::string;

class Huffman : public  TDAArbol{
    public:
        Huffman();
        virtual int contarCaracteres(string);
        virtual string crearHojas(string);
        virtual void imprimirHojas();
        virtual int getSize();
        virtual NodoArbol* creaArbol();
        virtual string BusquedaProfunda(NodoArbol*,string);
        virtual void decodificadorHuffman(NodoArbol*, string);
        virtual string codificarTexto(NodoArbol*,string);
    private:
        string frase;
        string generatingCode;
        string codeGenerated;
        LinkedList* hojasHuffman;
        int size;
        int maxFreq;
        LinkedQueue* colaDeArbol;
};


#endif //HUFFMAN_H
