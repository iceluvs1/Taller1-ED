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

    int notasCount;
    NodoNota* notasHead;
    NodoInscripcion* sig;

    NodoInscripcion(int idAlumno, int idCurso)
        : id_alumno(idAlumno), id_curso(idCurso), notasCount(0), notasHead(nullptr), sig(nullptr) {}
};