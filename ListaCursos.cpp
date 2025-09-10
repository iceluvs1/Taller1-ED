#include "ListaCursos.h"
#include "Utilidades.h"
#include <iostream>


ListaCursos::ListaCursos() : head(nullptr) {}

ListaCursos::~ListaCursos() {
    NodoCurso* nodoActual = head;
    while (nodoActual) {
        NodoCurso* sig = nodoActual->sig;
        delete nodoActual;
        nodoActual = sig;
    }
    head = nullptr;
    cantidad = 0;
}

// Función para buscar cursos por ID
NodoCurso* ListaCursos::buscarPorId(int id_curso) const {
    NodoCurso* nodoActual = head;
    while (nodoActual) {
        if (nodoActual->dato.id_curso() == id_curso)
            return nodoActual;
        nodoActual = nodoActual->sig;
    }
    return nullptr;
}



// Función para agregar curso
bool ListaCursos::agregarCurso(const Curso& curso) {
    // evitar IDs duplicados
    if (buscarPorId(curso.id_curso()) != nullptr) {
        std::cerr << "ERROR. Ya existe un curso con ese ID "
                  << curso.id_curso() << "\n";
        return false;
    }

    NodoCurso* nuevoNodo = new NodoCurso(curso);
    nuevoNodo->sig = head;
    head = nuevoNodo;
    cantidad++;
    std::cout << "Curso agregado con éxito.\n";
    return true;
}





