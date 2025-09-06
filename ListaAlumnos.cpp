#include <iostream>
#include "ListaAlumnos.h"
#include "Utilidades.h"


ListaAlumnos::ListaAlumnos() : head(nullptr), cantidad(0) {}

ListaAlumnos::~ListaAlumnos() {     // Destructor para cuando ListaAlumnos deje de existir
    NodoAlumno* nodoActual = head;
    while (nodoActual) {
        NodoAlumno* sig = nodoActual -> sig;
        delete nodoActual;
        nodoActual = sig;
    }
    head = nullptr;
    cantidad = 0;
}

// Función para buscar alumnos por ID
NodoAlumno* ListaAlumnos::buscarPorId(int id_alumno) const {
    NodoAlumno* nodoActual = head;
    while (nodoActual) {
        if (nodoActual->dato.id_alumno() == id_alumno) {
            return nodoActual; // ID encontrado
        }
        nodoActual = nodoActual->sig;
    }
    return nullptr; // ID no encontrado
}



// Función para agregar alumno
bool ListaAlumnos::agregarAlumno(const Alumno& alumno) {
    // evitar IDs duplicados
    if (buscarPorId(alumno.id_alumno()) != nullptr) {
        std::cerr << "ERROR. Ya existe un alumno con ese ID " << alumno.id_alumno() << "\n";
        return false;
    }

    NodoAlumno* nuevoNodo = new NodoAlumno(alumno);
    nuevoNodo -> sig = head;
    head = nuevoNodo;
    cantidad++;
    std::cout << "Alumno agregado con éxito.\n";
    return true;
}

// Función para buscar alumno por nombre
void ListaAlumnos::buscarPorNombre(const std::string& nombre){
    bool huboCoincidencias = false;
    int totalCoincidencias = 0;

    std::string nombreBuscadoMin = Utilidades::ignorarMayusculas(nombre);


    NodoAlumno* nodoActual = head;
    while (nodoActual) {
        std::string nombreNodoMin = Utilidades::ignorarMayusculas(nodoActual->dato.nombre());   // coincidencia exacta

        if (nombreNodoMin == nombreBuscadoMin) {
            if (!huboCoincidencias) {
                std::cout << "Coincidencias para nombre \"" << nombre << "\":\n";
                huboCoincidencias = true;
            }
            nodoActual->dato.mostrar();               // muestra la info COMPLETA
            ++totalCoincidencias;
        }
        nodoActual = nodoActual->sig;
    }

    if (!huboCoincidencias) {
        std::cout << "[No se encontraron alumnos con ese nombre]\n";
    } else {
        std::cout << "(Total coincidencias: " << totalCoincidencias << ")\n";
    }
}

// Función para eliminar alumno por ID
bool ListaAlumnos::eliminarPorId(int id_alumno) {
    NodoAlumno* nodoActual = head;
    NodoAlumno* nodoAnterior = nullptr;
    while (nodoActual) {
        if (nodoActual->dato.id_alumno() == id_alumno) {
            if (nodoAnterior) nodoAnterior->sig = nodoActual->sig;
            else head = nodoActual->sig;

            delete nodoActual;
            --cantidad;
            return true;
        }
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->sig;
    }
    return false;
}