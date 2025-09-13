#pragma once

class NodoNota {
public:
    float valor;
    NodoNota* sig;
    NodoNota(float v) : valor(v), sig(nullptr) {}
};



class NodoInscripcion {
public:
    int id_alumno;
    int id_curso;
    NodoInscripcion* sig;

    NodoNota* notasHead;
    int notasCount;

    NodoInscripcion(int idAlumno, int idCurso)
        : id_alumno(idAlumno), id_curso(idCurso), notasHead(nullptr),
        notasCount(0), sig(nullptr) {}
};