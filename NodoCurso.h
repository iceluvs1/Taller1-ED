#pragma once
#include "Curso.h"

class NodoCurso {
public:
    Curso dato;
    NodoCurso* sig;

    NodoCurso(const Curso& curso)
        : dato(curso), sig(nullptr) {}
};
