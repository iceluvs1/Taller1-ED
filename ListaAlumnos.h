#pragma once
#include "NodoAlumno.h"

class ListaAlumnos {
private:
    NodoAlumno* head;
    int n;

public:
    ListaAlumnos();
    ~ListaAlumnos();

    void agregarAlumno(const Alumno& alumno);
};