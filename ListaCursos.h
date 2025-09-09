#pragma once
#include <string>
#include <iostream>
#include "NodoCurso.h"
#include "ListaInscripciones.h"
#include "Utilidades.h"


class ListaCursos {
private:
    NodoCurso* head;

public:
    ListaCursos();
    ~ListaCursos();

    void agregar();
};
