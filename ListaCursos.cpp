#include "ListaCursos.h"
#include "ListaInscripciones.h"
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

// Función para buscar curso por nombre
void ListaCursos::buscarPorNombre(const std::string& nombre) const {
    bool huboCoincidencias = false;
    int totalCoincidencias = 0;

    std::string nombreBuscadoMin = Utilidades::ignorarMayusculas(nombre);

    NodoCurso* nodoActual = head;   // arrancamos desde la cabeza de la lista
    while (nodoActual) {            // mientras no lleguemos al final (nullptr)
        std::string nombreNodoMin =
            Utilidades::ignorarMayusculas(nodoActual->dato.nombre_curso());

        if (nombreNodoMin == nombreBuscadoMin) {
            if (!huboCoincidencias) {
                std::cout << "Coincidencias para nombre de curso \"" << nombre << "\":\n";
                huboCoincidencias = true;
            }
            nodoActual->dato.mostrar();   // muestra la info completa del curso
            ++totalCoincidencias;
        }
        nodoActual = nodoActual->sig;    // avanzar al siguiente nodo
    }

    if (!huboCoincidencias) {
        std::cout << "[No se encontraron cursos con ese nombre]\n";
    } else {
        std::cout << "(Total coincidencias: " << totalCoincidencias << ")\n";
    }
}

// Función para eliminar curso por ID
bool ListaCursos::eliminarPorId(int id_curso, ListaInscripciones& inscripciones) {
    NodoCurso* nodoActual = head;
    NodoCurso* nodoAnterior = nullptr;

    while (nodoActual) {
        if (nodoActual->dato.id_curso() == id_curso) {
            if (nodoAnterior) nodoAnterior->sig = nodoActual->sig;
            else head = nodoActual->sig;

            inscripciones.eliminarPorCurso(id_curso);

            delete nodoActual;
            --cantidad;
            return true;
        }
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->sig;
    }
    return false;
}

