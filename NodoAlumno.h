#pragma once
#include "Alumno.h"

class NodoAlumno {
public:
    Alumno dato;
    NodoAlumno* sig;

    NodoAlumno(const Alumno& alumno)
    : dato(alumno), sig(nullptr) {}
};