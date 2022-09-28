#include "LinkedList.h"
#include "iostream"
//#define NULL 0
using namespace std;

LinkedList::LinkedList()
{
    inicio=NULL;
    final=NULL;
    n=0;
}

LinkedList::~LinkedList()
{
    if(inicio)
        delete inicio;
}

void LinkedList::anula(){
    delete inicio;
    final = NULL;
    n = 0;
}

bool LinkedList::inserta(Object* item, int posicion){

    if (posicion>=1 && posicion<=n+1){
        Nodo* newNode = new Nodo();
        //nodo raiz
        if(this->n ==0)
        {
            newNode->setItem(item);
            this->inicio = newNode;
            this->final = newNode;
            n++;
        }
        else if (posicion==n+1){
            append(item);
        }
        else{
            newNode->setItem(item);
            Nodo* temp = inicio;

            for (int i=1; i<posicion; i++)
                temp=temp->getSiguiente();
            temp->getAnterior()->setSiguiente(newNode);
            newNode->setAnterior(temp->getAnterior());
            newNode->setSiguiente(temp);
            temp->setAnterior(newNode);
            n++;
        }

        return true;
    }else
        return false;
}

Object* LinkedList::siguiente(int posicion){
    return recupera(posicion + 1);
}

Object* LinkedList::anterior(int posicion){
    return recupera(posicion - 1);
}

void LinkedList::append(Object* item){
    Nodo* temp = new Nodo();
    temp->setItem(item);
    final->setSiguiente(temp);
    temp->setAnterior(final);
    final = temp;
    n++;
}

void LinkedList::imprimir_lista(){
    Nodo* temp = inicio;
    for(int i=1; i<=n; i++){
        cout<< (temp->getItem()->toString()) << endl;
        temp = temp->getSiguiente();
    }
}

bool LinkedList::suprime(int posicion){
    if (posicion>=1 && posicion<=n){
        Nodo* temp = NULL;
        if (posicion==1){
            temp = inicio;
            inicio = inicio->getSiguiente();
            temp->setSiguiente(NULL);
            inicio->setAnterior(NULL);

        }else if (posicion == n){
            temp = final;
            final = final->getAnterior();
            final->setSiguiente(NULL);
            temp->setAnterior(NULL);

        }else{
            temp = inicio;
            for (int i=1; i<=posicion; i++)
                temp=temp->getSiguiente();
            temp->getAnterior()->setSiguiente(temp->getSiguiente());
            temp->getSiguiente()->setAnterior(temp->getAnterior());
            temp->setSiguiente(NULL);
            temp->setAnterior(NULL);
        }
        delete temp;
        n--;
        return true;
    }else
        return false;

}

Object* LinkedList::recupera(int posicion){
    Nodo* temp = NULL;
    posicion -= 1;
    if (posicion >= 0 && posicion <= n){
        temp = inicio;
        if(posicion==0)
            return temp->getItem();

        for (int i=1; i<=posicion; i++)
            temp = temp->getSiguiente();
        return temp->getItem();
    }else
        return NULL;
}

int LinkedList::localiza(Object* item){
    Nodo* temp = NULL;
    temp = inicio;
    for (int i=1; i<= n; i++){
        //if (temp->getItem()->equals(item))
        if (temp->getItem()->toString() == item->toString())
            return i;
        else
            temp = temp->getSiguiente();
    }
    return -1;
}

Object* LinkedList::primero(){
    if (n >= 1)
        return inicio->getItem();
    else
        return NULL;
}

bool LinkedList::vacia(){
    if (n>0)
        return false;
    else
        return true;
}

Nodo* LinkedList::getInicio() {
    return this->inicio;
}