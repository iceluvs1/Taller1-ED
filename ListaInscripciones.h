#pragma once
#include "NodoInscripcion.h"
#include <iostream>

class ListaAlumnos;
class ListaCursos;

class ListaInscripciones {
private:
    NodoInscripcion* head;
    int cantidad;

    // Complementos para las notas
    static bool notaValida(float n) { return n >= 1.0f && n <= 7.0f; }
    static void notas_push_front(NodoInscripcion* ins, float n);
    static void notas_clear(NodoInscripcion* ins);
    static void notas_print(const NodoInscripcion* ins);

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


    // MANEJO DE NOTAS
    bool agregarNota(int id_alumno, int id_curso, float nota);
    bool verNotas(int id_alumno, int id_curso) const;


    // CONSULTAS Y REPORTES
    void listarCursosDeAlumno(int id_alumno, const ListaCursos& cursos) const;
    bool promedioAlumnoEnCurso(int id_alumno, int id_curso, float& promedio) const;
    bool promedioGeneralAlumno(int id_alumno, float& promedioGeneral) const;


};
