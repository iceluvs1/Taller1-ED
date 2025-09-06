#pragma once
#include <iostream>
#include <algorithm>
#include <cctype>

class Utilidades {
public:
    // IGNORA LAS MAYÚSCULAS DE UN STRING (convierte el string a minúsculas)
    static std::string ignorarMayusculas(const std::string& texto) {
        std::string copia = texto;
        std::transform(copia.begin(), copia.end(), copia.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        return copia;
    }

};

