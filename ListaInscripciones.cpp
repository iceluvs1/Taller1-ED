#include "ListaInscripciones.h"
#include "ListaAlumnos.h"
#include "ListaCursos.h"
#include <iostream>
#include <iomanip> // para decimales

// complementos de la sublista de notas
void ListaInscripciones::notas_push_front(NodoInscripcion* inscripcion, float nota) {
    NodoNota* nuevaNota = new NodoNota(nota);
    nuevaNota->sig = inscripcion->notasHead;
    inscripcion->notasHead = nuevaNota;
    inscripcion->notasCount++;
}

void ListaInscripciones::notas_clear(NodoInscripcion* inscripcion) {
    NodoNota* notaActual = inscripcion->notasHead;
    while (notaActual) {
        NodoNota* siguienteNota = notaActual->sig;
        delete notaActual;
        notaActual = siguienteNota;
    }
    inscripcion->notasHead = nullptr;
    inscripcion->notasCount = 0;
}

void ListaInscripciones::notas_print(const NodoInscripcion* inscripcion) {
    if (!inscripcion->notasHead) {
        std::cout << "[Sin notas registradas]\n";
        return;
    }
    std::cout << "Notas: ";
    const NodoNota* notaActual = inscripcion->notasHead;
    bool esPrimera = true;
    while (notaActual) {
        if (!esPrimera) std::cout << ", ";
        std::cout << std::fixed << std::setprecision(1) << notaActual->valor;
        esPrimera = false;
        notaActual = notaActual->sig;
    }
    std::cout << "\n";
}

// Destructor (limpia también las notas)
ListaInscripciones::~ListaInscripciones() {
    NodoInscripcion* actual = head;
    while (actual) {
        NodoInscripcion* siguiente = actual->sig;
        notas_clear(actual);   // limpia sublista de notas
        delete actual;
        actual = siguiente;
    }
    head = nullptr;
    cantidad = 0;
}

// Consultas
bool ListaInscripciones::estaInscrito(int id_alumno, int id_curso) const {
    for (NodoInscripcion* actual = head; actual; actual = actual->sig) {
        if (actual->id_alumno == id_alumno && actual->id_curso == id_curso) return true;
    }
    return false;
}

// Inscribir / Desinscribir
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
    NodoInscripcion* nuevaIns = new NodoInscripcion(id_alumno, id_curso);
    nuevaIns->sig = head;
    head = nuevaIns;
    ++cantidad;
    std::cout << "Inscripción realizada.\n";
    return true;
}

bool ListaInscripciones::desinscribir(int id_alumno, int id_curso) {
    NodoInscripcion* actual = head;
    NodoInscripcion* anterior = nullptr;

    while (actual) {
        if (actual->id_alumno == id_alumno && actual->id_curso == id_curso) {
            if (anterior) anterior->sig = actual->sig;
            else head = actual->sig;

            notas_clear(actual);  // importante para no filtrar memoria
            delete actual;
            --cantidad;
            std::cout << "Inscripción eliminada.\n";
            return true;
        }
        anterior = actual;
        actual = actual->sig;
    }
    return false; // no estaba inscrito
}

void ListaInscripciones::eliminarPorCurso(int id_curso) {
    NodoInscripcion* actual = head;
    NodoInscripcion* anterior = nullptr;

    while (actual) {
        if (actual->id_curso == id_curso) {
            NodoInscripcion* aBorrar = actual;
            if (anterior) anterior->sig = actual->sig;
            else head = actual->sig;

            actual = actual->sig;
            notas_clear(aBorrar);   // limpia notas antes de borrar
            delete aBorrar;
            --cantidad;
        } else {
            anterior = actual;
            actual = actual->sig;
        }
    }
}

void ListaInscripciones::eliminarPorAlumno(int id_alumno) {
    NodoInscripcion* actual = head;
    NodoInscripcion* anterior = nullptr;

    while (actual) {
        if (actual->id_alumno == id_alumno) {
            NodoInscripcion* aBorrar = actual;
            if (anterior) anterior->sig = actual->sig;
            else head = actual->sig;

            actual = actual->sig;
            notas_clear(aBorrar);
            delete aBorrar;
            --cantidad;
        } else {
            anterior = actual;
            actual = actual->sig;
        }
    }
}

//  MANEJO DE NOTAS
bool ListaInscripciones::agregarNota(int id_alumno, int id_curso, float nota) {
    if (!notaValida(nota)) {
        std::cerr << "ERROR. La nota debe estar entre 1.0 y 7.0\n";
        return false;
    }
    for (NodoInscripcion* actual = head; actual; actual = actual->sig) {
        if (actual->id_alumno == id_alumno && actual->id_curso == id_curso) {
            notas_push_front(actual, nota);  // O(1)
            std::cout << "Nota registrada.\n";
            return true;
        }
    }
    std::cerr << "ERROR. No existe esa inscripcion (alumno/curso).\n";
    return false;
}

bool ListaInscripciones::verNotas(int id_alumno, int id_curso) const {
    for (NodoInscripcion* actual = head; actual; actual = actual->sig) {
        if (actual->id_alumno == id_alumno && actual->id_curso == id_curso) {
            notas_print(actual);
            return true;
        }
    }
    std::cerr << "ERROR. No existe esa inscripcion (alumno/curso).\n";
    return false;
}


// PROMEDIO NOTAS
static bool promedioNotasIns(const NodoInscripcion* ins, float& out) {
    if (!ins || !ins->notasHead || ins->notasCount <= 0) return false;
    float suma = 0.0f;
    int n = 0;
    for (const NodoNota* actual = ins->notasHead; actual; actual = actual->sig) {
        suma += actual->valor;
        ++n;
    }
    if (n == 0) return false;
    out = suma / n;
    return true;
}

bool ListaInscripciones::promedioAlumnoEnCurso(int id_alumno, int id_curso, float& promedio) const {
    for (NodoInscripcion* actual = head; actual; actual = actual->sig) {
        if (actual->id_alumno == id_alumno && actual->id_curso == id_curso) {
            return promedioNotasIns(actual, promedio); // true si tiene notas
        }
    }
    std::cerr << "ERROR. No existe esa inscripcion (alumno/curso).\n";
    return false;
}

// Mostrar cursos de un alumnos
void ListaInscripciones::listarCursosDeAlumno(int id_alumno, const ListaCursos& cursos) const {
    bool hubo = false;
    int total = 0;
    for (NodoInscripcion* actual = head; actual; actual = actual->sig) {
        if (actual->id_alumno == id_alumno) {
            auto nodoCurso = cursos.buscarPorId(actual->id_curso);
            if (!hubo) {
                std::cout << "Cursos del alumno ID " << id_alumno << ":\n";
                hubo = true;
            }
            if (nodoCurso) nodoCurso->dato.mostrar();
            else std::cout << "[Curso ID " << actual->id_curso << " no existe]\n";
            ++total;
        }
    }
    if (!hubo) {
        std::cout << "[El alumno no tiene cursos inscritos]\n";
    }
    else{
        std::cout << "(Total: " << total << ")\n";
    }
}

// Promedio general de un alumno (según sus promedios finales)
bool ListaInscripciones::promedioGeneralAlumno(int id_alumno, float& promedioGeneral) const {
    float acum = 0.0f;
    int cantidadCursos = 0;
    for (NodoInscripcion* it = head; it; it = it->sig) {
        if (it->id_alumno == id_alumno) {
            float pCurso = 0.0f;
            if (promedioNotasIns(it, pCurso)) {
                acum += pCurso;
                ++cantidadCursos;
            }
        }
    }
    if (cantidadCursos == 0) return false;  // no tiene cursos con notas registradas
    promedioGeneral = acum / cantidadCursos;
    return true;
}

