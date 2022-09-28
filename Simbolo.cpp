#include "Simbolo.h"

using namespace std;

Simbolo::Simbolo()
{
    this->simbolo= '\0';
}

//definiendo las clases virtuales
bool Simbolo::equals(Object* item){}

string  Simbolo::toString() {
    temp = this->simbolo;
    //temp.append(" freq : ");
    //temp.append(to_string(this->freq));
    return temp;
}

void Simbolo::setSimbolo(char _simbolo) {
    this->simbolo = _simbolo;
}

char Simbolo::getSimbolo(){
    return this->simbolo;
}

void Simbolo::setFreq(int _freq) {
    this->freq = _freq;
}

int Simbolo::getFreq() {
    return this->freq;
}
