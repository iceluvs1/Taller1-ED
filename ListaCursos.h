#pragma once
#include <string>
#include <iostream>
#include "NodoCurso.h"
#include "ListaInscripciones.h"
#include "Utilidades.h"


class ListaCursos {
private:
    NodoCurso* head;
    int cantidad;

public:
    ListaCursos();
    ~ListaCursos();

    bool agregarCurso(const Curso& curso);
    NodoCurso* buscarPorId(int id_curso) const;
    void buscarPorNombre(const std::string& nombre) const;
    bool eliminarPorId(int id_curso);
    int totalCursos() const;
};
