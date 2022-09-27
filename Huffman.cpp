//
// Created by shello on 09-27-22.
//

#include "Huffman.h"
#include <iostream>


using namespace std;

Huffman::Huffman() {
    this->frase="0";
}

int Huffman::contarCaracteres(string _input) {
    cout << "Tiene un total de:" << _input.length() << "Characteres" << endl;
    for (int i = 0; i < _input.length(); ++i) {
        cout << " [ " << i << " ] " <<  " [ " << _input[i] << " ] " << endl;
    }
    return _input.length();
}

bool Huffman::crearHojas(string _input) {

    for (int i = 0; i < _input.length(); ++i) {
        if(i == 0){
            this->inicio = new Nodo();
            HojaHuffman* newHoja = new HojaHuffman();
            newHoja->setHoja(_input[i], 1, "0");
            this->inicio->setItem(newHoja);
        }
    }
}
