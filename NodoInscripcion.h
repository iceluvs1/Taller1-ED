#pragma once

class NodoInscripcion {
public:
    int id_alumno;
    int id_curso;
    NodoInscripcion* sig;

    NodoInscripcion(int idAlumno, int idCurso)
        : id_alumno(idAlumno), id_curso(idCurso), sig(nullptr) {}
};