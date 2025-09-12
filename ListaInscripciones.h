#pragma once
#include "NodoInscripcion.h"
#include <iostream>

class ListaAlumnos;
class ListaCursos;

class ListaInscripciones {
private:
    NodoInscripcion* head;
    int cantidad;

public:
    ListaInscripciones() : head(nullptr), cantidad(0) {}
    ~ListaInscripciones();

    // Inscribir un alumno en un curso (valida existencia, duplicados y cupos)
    bool inscribir(int id_alumno, int id_curso, const ListaAlumnos& alumnos, const ListaCursos& cursos);

    // Eliminar inscripción específica
    bool desinscribir(int id_alumno, int id_curso);

    // Cuando se elimina un curso: borrar todas sus inscripciones
    void eliminarPorCurso(int id_curso);

    // Cuando se elimina un alumno: borrar todas sus inscripciones
    void eliminarPorAlumno(int id_alumno);

    // Consultas
    bool estaInscrito(int id_alumno, int id_curso) const;


};
