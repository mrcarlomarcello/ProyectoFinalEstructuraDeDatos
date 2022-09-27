#pragma once
//
// Created by shello on 09-27-22.
//

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "TDAArbol.h"
#include "HojaHuffman.h"
#include "Nodo.h"

class Huffman : public  TDAArbol{
    public:
        Huffman();
        virtual int contarCaracteres(string);
        virtual bool crearHojas(string);

    private:
        string frase;
        Nodo* inicio;

};


#endif //HUFFMAN_H
