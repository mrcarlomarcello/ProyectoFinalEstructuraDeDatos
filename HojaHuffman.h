#pragma once
//
// Created by shello on 09-27-22.
//

#ifndef HOJAHUFFMAN_H
#define HOJAHUFFMAN_H

#include "Object.h"
#include <string>
using std::string;

class HojaHuffman : public Object{

    public:
        HojaHuffman();
        void setHoja(char, int, string);
    protected:
        char value;
        int freq;
        string huffmanCode;
};


#endif //HOJAHUFFMAN_H
