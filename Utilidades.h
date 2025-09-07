#pragma once
#include <iostream>
#include <algorithm>
#include <cctype>
#include <regex>

class Utilidades {
public:
    // IGNORA LAS MAYÚSCULAS DE UN STRING (convierte el string a minúsculas)
    static std::string ignorarMayusculas(const std::string& texto) {
        std::string copia = texto;
        std::transform(copia.begin(), copia.end(), copia.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        return copia;
    }

    // Verifica solo formato DD/MM/AAAA
    static bool fechaFormatoValido(const std::string& texto) {
        static const std::regex re(R"(^(0[1-9]|[12][0-9]|3[0-1])/(0[1-9]|1[0-2])/\d{4}$)");
        return std::regex_match(texto, re);
    }

    // Solo dígitos (ID)
    static bool esNumeroEnteroPositivo(const std::string& texto) {
        static const std::regex re("^[0-9]+$");
        return std::regex_match(texto, re);
    }

    // Solo letras + espacios (incluye tildes y ñ)
    static bool esSoloLetrasEspacios(const std::string& texto) {
        static const std::regex re(R"(^[A-Za-zÁÉÍÓÚÜÑáéíóúüñ ]+$)");
        return !texto.empty() && std::regex_match(texto, re);
    }

};

