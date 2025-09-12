#include "ListaInscripciones.h"
#include "ListaAlumnos.h"
#include "ListaCursos.h"
#include <iostream>

ListaInscripciones::~ListaInscripciones() {
    NodoInscripcion* nodoActual = head;
    while (nodoActual) {
        NodoInscripcion* sig = nodoActual->sig;
        delete nodoActual;
        nodoActual = sig;
    }
    head = nullptr;
    cantidad = 0;
}

bool ListaInscripciones::estaInscrito(int id_alumno, int id_curso) const {
    for (NodoInscripcion* nodoActual = head; nodoActual; nodoActual = nodoActual->sig)
        if (nodoActual->id_alumno == id_alumno && nodoActual->id_curso == id_curso) return true;
    return false;
}

bool ListaInscripciones::inscribir(int id_alumno, int id_curso, const ListaAlumnos& alumnos, const ListaCursos& cursos) {
    // validar existencia
    if (!alumnos.buscarPorId(id_alumno)) {
        std::cerr << "ERROR. Alumno no existe.\n";
        return false;
    }
    if (!cursos.buscarPorId(id_curso)) {
        std::cerr << "ERROR. Curso no existe.\n";
        return false;
    }

    // evitar duplicados
    if (estaInscrito(id_alumno, id_curso)) {
        std::cerr << "ERROR. Ya está inscrito en ese curso.\n";
        return false;
    }

    // insertar al inicio
    NodoInscripcion* nuevo = new NodoInscripcion(id_alumno, id_curso);
    nuevo->sig = head;
    head = nuevo;
    ++cantidad;
    std::cout << "Inscripción realizada.\n";
    return true;
}

bool ListaInscripciones::desinscribir(int id_alumno, int id_curso) {
    NodoInscripcion* nodoActual = head;
    NodoInscripcion* ant = nullptr;

    while (nodoActual) {
        if (nodoActual->id_alumno == id_alumno && nodoActual->id_curso == id_curso) {
            if (ant) ant->sig = nodoActual->sig; else head = nodoActual->sig;
            delete nodoActual;
            --cantidad;
            std::cout << "Inscripción eliminada.\n";
            return true;
        }
        ant = nodoActual;
        nodoActual = nodoActual->sig;
    }
    return false; // no estaba inscrito
}

void ListaInscripciones::eliminarPorCurso(int id_curso) {
    NodoInscripcion* nodoActual = head;
    NodoInscripcion* ant = nullptr;

    while (nodoActual) {
        if (nodoActual->id_curso == id_curso) {
            NodoInscripcion* borrar = nodoActual;
            if (ant) ant->sig = nodoActual->sig; else head = nodoActual->sig;
            nodoActual = nodoActual->sig;
            delete borrar;
            --cantidad;
        } else {
            ant = nodoActual;
            nodoActual = nodoActual->sig;
        }
    }
}
