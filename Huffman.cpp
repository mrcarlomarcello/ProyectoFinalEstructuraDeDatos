//
// Created by shello on 09-27-22.
//

#include "Huffman.h"
#include <iostream>
#include "Simbolo.h"

using namespace std;

Huffman::Huffman() {
    this->frase="0";
    this->hojasHuffman = new LinkedList();
    this->size=0;
    this->maxFreq=0;
    this->colaDeArbol = new LinkedQueue();
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
            //hojasHuffman->append(valor);
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
                //hojasHuffman->append(valor);
            }

        }
    }

    hojasHuffman->imprimir_lista();
    //cout << "imprimio la lista" << endl;
    //imprimirHojas();
    //cout << "imprimio las hojas" << endl;
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

NodoArbol* Huffman::creaArbol() {

    Nodo* temp = this->hojasHuffman->getInicio();

    //Arma las hojas del arbol
    for (int i = 1; i < this->maxFreq ; ++i) {

        for (int j = 0; j < this->size; ++j) {
            Simbolo* tempValor = (Simbolo*)temp->getItem();
            if(tempValor->getFreq() == i)
                this->colaDeArbol->pone_en_cola(temp->getItem());
            temp = temp->getSiguiente();
        }
        temp = this->hojasHuffman->getInicio();
    }

    this->colaDeArbol->imprime_cola();

    //** PROBADOR DE QUE LA COLA VA EN ORDEN
    do{
        Simbolo* tempValor = (Simbolo*)this->colaDeArbol->saca_de_cola();
        cout << "Saque para probar: " << tempValor->toString() << "  con frecuencia:  " <<tempValor->getFreq() << endl;
    } while (!colaDeArbol->vacia());


    //Huffman Node tentativo pt1.
    //LinkedQueue* huffmanTree = new LinkedQueue();
    //**
    //do{
    //    Simbolo* tempValor = (Simbolo*)this->colaDeArbol->saca_de_cola();
        //NodoArbol* nodoArbolTemporal;
        //nodoArbolTemporal->setItem(tempValor);
        //huffmanTree->pone_en_cola(nodoArbolTemporal);
    //   cout << "Saque para probar: " << tempValor->toString() << "  con frecuencia:  " <<tempValor->getFreq() << endl;
    //} while (!colaDeArbol->vacia());

    /***
    do{
        NodoArbol* nodoArbolTemporal = (NodoArbol*)huffmanTree->saca_de_cola();
        Simbolo* tempValor = (Simbolo*)nodoArbolTemporal->getItem();
        cout << "Saque para probar: Del ArbolHUFFMAN" << tempValor->toString() << "  con frecuencia:  " <<tempValor->getFreq() << endl;
    }while(!huffmanTree->vacia());
    ***/



    return NULL;

}
