//
// Created by shello on 09-27-22.
//

#include "Huffman.h"
#include <iostream>
#include "Simbolo.h"

using namespace std;

Huffman::Huffman() {
    this->frase="0";
    this->codeGenerated="";
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

string Huffman::crearHojas(string _input) {

    cout << "Creando Hojas de: " << _input.length() << "Caracteres" << endl;
    cout << "Vamos a hacer la tabla de valores repetidos" << endl;

    for (int i = 0; i < _input.length(); ++i) {

        Simbolo* valor = new Simbolo();
        valor->setSimbolo(_input[i]);
        valor->setFreq(1);

        if(i==0){
            this->size+=1;
            hojasHuffman->inserta(valor,this->size);
            cout << "Insertamos el siguiente Valor: " << valor->getSimbolo() <<  " con la siguiente frecuencia: " << to_string(valor->getFreq()) << endl;
        }
        else {
            //query compara tamaño de objeto con tamaño de objeto
            int query = hojasHuffman->localiza(valor);

            if(query!=-1){

                Simbolo* temp = (Simbolo*)hojasHuffman->recupera(query);
                int freqTemp = temp->getFreq()+1;
                temp->setFreq(freqTemp);

                //revisamos si es la mayor Frecuencia registrada
                if(freqTemp >= this->maxFreq)
                    this->maxFreq=freqTemp;

                cout << "valor encontrado: "<< temp->getSimbolo() << " Frecuencia: " << freqTemp << endl;

            }
            else{
                this->size+=1;
                cout << "Insertamos el siguiente Valor: " << valor->getSimbolo() <<  " con la siguiente frecuencia: " << to_string(valor->getFreq()) << endl;
                hojasHuffman->inserta(valor,this->size);
            }
        }
    }
    return _input;
}

void Huffman::imprimirHojas() {
    Nodo* temp = this->hojasHuffman->getInicio();
    int k = 1;

    do{
        Simbolo* tempsimbolo = (Simbolo*)temp->getItem();
        cout << k << " " << tempsimbolo->getSimbolo() << " Freq " << to_string(tempsimbolo->getFreq()) << endl;
        temp = temp->getSiguiente();
        k++;
    }while(temp!=NULL);

}

int Huffman::getSize() {
    return this->size;
}

NodoArbol* Huffman::creaArbol() {


    //Arma las hojas del arbol
    Nodo* temp = this->hojasHuffman->getInicio();
    for (int i = 0; i <= this->maxFreq ; ++i) {

        for (int j = 0; j < this->size; ++j) {
            Simbolo* tempValor = (Simbolo*)temp->getItem();
            if(tempValor->getFreq() == i)
                this->colaDeArbol->pone_en_cola(temp->getItem());
            temp = temp->getSiguiente();
        }
        temp = this->hojasHuffman->getInicio();
    }
    cout << "HACE HOJAS!!!!!!!!!" << endl;
    //Arma las hojas del arbol

    //CREA UN ARBOL -> PRIMER NIVEL MULTIPLES NODOS HUFFMAN
    LinkedQueue* huffmanTree = new LinkedQueue();
    do{
        Simbolo* tempValor = (Simbolo*)this->colaDeArbol->saca_de_cola();
        NodoArbol* nodoArbolTemporal = new NodoArbol();
        nodoArbolTemporal->setItem(tempValor);
        huffmanTree->pone_en_cola(nodoArbolTemporal);
        //cout << "Saque nodos y convertí a NODOS ARBOL: " << tempValor->toString() << "  con frecuencia:  " <<tempValor->getFreq() << endl;
    } while (!colaDeArbol->vacia());
    cout << "HACE NODOS HUFFMAN!!!!!!!!!" << endl;
    //CREA UN ARBOL -> PRIMER NIVEL MULTIPLES NODOS HUFFMAN

    //CREA ARBOL CON UN SOLO NODO
    do{
        NodoArbol* nodoArbolTemporal1 = (NodoArbol*)huffmanTree->saca_de_cola();

        if(!huffmanTree->vacia()){

            NodoArbol* nodoArbolTemporal2 = (NodoArbol*)huffmanTree->saca_de_cola();
            Simbolo* nodeSimbolo = new Simbolo();
            int frecuencia = ((Simbolo*)nodoArbolTemporal1->getItem())->getFreq()
                    + ((Simbolo*)nodoArbolTemporal2->getItem())->getFreq();

            nodeSimbolo->setSimbolo('\0');
            nodeSimbolo->setFreq(frecuencia);

            NodoArbol* nodoArbolTemporal3 = new NodoArbol();
            nodoArbolTemporal3->setItem(nodeSimbolo);
            nodoArbolTemporal3->setHijoIzquierdo(nodoArbolTemporal1);
            nodoArbolTemporal3->setHijoDerecho(nodoArbolTemporal2);
            huffmanTree->pone_en_cola(nodoArbolTemporal3);
            cout << "ARME UN NODO HUFFMAN: " << " Con frecuencia de " << frecuencia <<endl;
        }
        else{
            return nodoArbolTemporal1;
        }

    }while(!huffmanTree->vacia());
    //CREA ARBOL CON UN SOLO NODO

    return NULL;

}

string Huffman::BusquedaProfunda(NodoArbol* arbolTemp, string _char){


    if( arbolTemp->getHijoIzquierdo() ){
        this->generatingCode.append("0");
        BusquedaProfunda(arbolTemp->getHijoIzquierdo(), _char);
        this->generatingCode.pop_back();
    }

    if( arbolTemp->getHijoDerecho() ){
        this->generatingCode.append("1");
        BusquedaProfunda(arbolTemp->getHijoDerecho(), _char);
        this->generatingCode.pop_back();
    }
    Simbolo* compara = (Simbolo*)arbolTemp->getItem();
    //determinar si es hoja con hijos vacios
    if(arbolTemp->getHijoIzquierdo() == NULL && arbolTemp->getHijoDerecho() == NULL){
        if(compara->toString() == _char)  // <<<<<---- OJO AQUI CON ESE OBJETO
        {
            cout << "FOUND IT!!!" << endl;
            cout << this->generatingCode << endl;
            this->codeGenerated = this->generatingCode;
            return this->codeGenerated;
        }

    }
    return this->codeGenerated;

}

void Huffman::decodificadorHuffman(NodoArbol* _Arbol, string secreto){
    NodoArbol* temp = _Arbol;

    for (int i = 0; i < secreto.length() ; ++i) {
        //selector de nodo
        if(secreto[i] == '0'){
            temp = temp->getHijoIzquierdo();
        }
        if(secreto[i] == '1')
        {
            temp = temp->getHijoDerecho();
        }
        //selector de nodo

        //Si tocamos Fondo Imprime y vuelve a salir al primer nodo
        if( temp->getHijoIzquierdo() == NULL && temp->getHijoDerecho() == NULL){
            Simbolo* temporal = (Simbolo*)temp->getItem();
            cout << temporal->getSimbolo();
            temp = _Arbol;
        }

    }

    cout << endl;

}

string Huffman::codificarTexto(NodoArbol * _Arbol, string _texto) {

    string codigoSecreto = "";
    for (int i = 0; i < _texto.length(); ++i) {
        string temp = "";
        temp += (_texto[i]);
        codigoSecreto += BusquedaProfunda(_Arbol, temp);
    }
    return codigoSecreto;
}
