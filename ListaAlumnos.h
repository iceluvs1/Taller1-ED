#pragma once
#include "NodoAlumno.h"

class ListaAlumnos {
private:
    NodoAlumno* head;
    int cantidad;

public:
    ListaAlumnos();
    ~ListaAlumnos();

    bool agregarAlumno(const Alumno& alumno);
    NodoAlumno* buscarPorId(int id_alumno) const;
    void buscarPorNombre(const std::string& nombre);
    bool eliminarPorId(const int id_alumno);
    void listarPorCarrera(const std::string& carrera) const;
};