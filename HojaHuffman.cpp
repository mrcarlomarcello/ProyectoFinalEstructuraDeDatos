//
// Created by shello on 09-27-22.
//
#include "HojaHuffman.h"

HojaHuffman::HojaHuffman() {
    this->value='0';
    this->huffmanCode="0";
    this->freq=0;
}
//definiendo las clases virtuales
bool HojaHuffman::equals(Object* item){
}

string HojaHuffman::toString() {
    string hoja;
    hoja = "Value: " + this->value + "  freq: " + this->freq + "HuffmanCode: " + this->huffmanCode;
    return hoja;
}

void HojaHuffman::setHoja(char _Value, int _freq, string _huffmanCode) {
    this->value = _Value;
    this->freq = _freq;
    this->huffmanCode = _huffmanCode;
}