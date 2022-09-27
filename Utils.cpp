//
// Created by shello on 09-26-22.
//

#include "Utils.h"
#include <iostream>
#include <ctype.h>

#include <string>
#include <fstream>
#include <streambuf>

using namespace std;

bool Utils::EsUnNumero(const char* cadena)
{
    for( ; *cadena; ++cadena )
    {
        // En cuanto un caracter no sea numérico
        if( !isdigit(*cadena) )
            return false;
    }

    return true;
}

string Utils::leerArchivo(string _name) {
    ifstream t(_name);
    string strRead((std::istreambuf_iterator<char>(t)),                    std::istreambuf_iterator<char>());
    return strRead;
}