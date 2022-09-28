//
// Created by shello on 09-27-22.
//

#include "Huffman.h"
#include <iostream>


using namespace std;

Huffman::Huffman() {
    this->frase="0";
    this->hojasHuffman = new LinkedList();
    this->size=0;
    this->maxFreq=0;
}

int Huffman::contarCaracteres(string _input) {
    cout << "Tiene un total de:" << _input.length() << "Characteres" << endl;
    for (int i = 0; i < _input.length(); ++i) {
        cout << " [ " << i << " ] " <<  " [ " << _input[i] << " ] " << endl;
    }
    this->frase = _input;
    return _input.length();
}

bool Huffman::crearHojas(string _input) {

    cout << "Creando Hojas de: " << _input.length() << "Caracteres" << endl;
    cout << "Vamos a hacer la tabla de valores repetidos" << endl;


    for (int i = 0; i < _input.length(); ++i) {

        Simbolo* valor = new Simbolo();
        valor->setSimbolo(_input[i]);
        valor->setFreq(1);

        if(i==0){
            this->size+=1;
            hojasHuffman->inserta(valor,this->size);
        }else {
            //query compara tamaño de objeto con tamaño de objeto
            int query = hojasHuffman->localiza(valor);

            if(query!=-1){
                Simbolo* temp = (Simbolo*)hojasHuffman->recupera(query);
                int freqTemp = temp->getFreq()+1;
                temp->setFreq(freqTemp);
                cout << _input[i] << endl;
                cout << "valor encontrado " << endl;
            }else{
                this->size+=1;
                hojasHuffman->inserta(valor,this->size);
            }

        }
    }
    hojasHuffman->imprimir_lista();
    cout << "imprimio la lista" << endl;
    imprimirHojas();
    cout << "imprimio las hojas" << endl;
    return false;

}

void Huffman::imprimirHojas() {
    Nodo* temp = this->hojasHuffman->getInicio();
    int k = 1;

    do{
        Simbolo* tempsimbolo = (Simbolo*)temp->getItem();
        cout << k << " " << tempsimbolo->getSimbolo() << " Freq " << tempsimbolo->getFreq() << endl;
        if(tempsimbolo->getFreq()>=this->maxFreq)
            this->maxFreq = tempsimbolo->getFreq();
        temp = temp->getSiguiente();
        k++;
    }while(temp!=NULL);

    cout << "Frecuencia Maxima" << this->maxFreq << endl;
}

int Huffman::getSize() {
    return this->size;
}

bool Huffman::creaArbol() {

    Nodo* temp = this->hojasHuffman->getInicio();

    do{

    }while(treesize>1);

}
