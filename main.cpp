#include <iostream>
#include <limits>
#include "Alumno.h"
#include "ListaAlumnos.h"
#include "NodoAlumno.h"
#include "Utilidades.h"


void menuManejoAlumnos(ListaAlumnos& lista);

int main() {
    Alumno juan(1, "Juan", "Perez", "Ingeniero", "2020");
    juan.mostrar();

    ListaAlumnos listaA;
    int opcion = -1;

    do {
        std::cout << "\n--- Menu ---\n";
        std::cout << "1. Manejo de Alumnos\n";
        std::cout << "2. Manejo de Cursos\n";
        std::cout << "3. Manejo de Inscripciones\n";
        std::cout << "4. Manejo de Notas\n";
        std::cout << "5. Consultas y Reportes\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cin.clear(); // limpia el error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida, intente de nuevo.\n";
            opcion = -1; // valor inválido para que no salga del menú
            continue;
        }

        switch (opcion) {
            case 1: {
                menuManejoAlumnos(listaA);
                break;

            }
            case 0:
                std::cout << "MENÚ CERRADO CON ÉXITO\n";
                break;
            default:
                std::cout << "Opción inválida, intente de nuevo.\n";
                break;
        }



    }while (opcion != 0);
    return 0;
}


// FUNCIÓN PARA MANEJO DE ALUMNOS
void menuManejoAlumnos(ListaAlumnos& lista) {
    int opcionAlumno;
    do {
        std::cout << "\n=== Manejo de Alumnos ===\n";
        std::cout << "1. Crear alumno\n";
        std::cout << "2. Buscar alumno por ID\n";
        std::cout << "3. Buscar alumno por nombre\n";
        std::cout << "4. Eliminar alumno por ID\n";
        std::cout << "0. Volver al menú principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcionAlumno;

        // Manejar errores de entrada del usuario
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida, intente de nuevo.\n";
            opcionAlumno = -1; // fuerza seguir en el menú
            continue;
        }

        if (opcionAlumno == 1) {
            // limpia el "\n" que dejó opcionAlumno
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::string sId;
            int id;
            std::string nombre, apellido, carrera, fechaIngreso;

            while (true) {  // Ingrese ID con control de error
                std::cout << "Ingrese ID: ";
                std::getline(std::cin, sId);
                if (Utilidades::esNumeroEnteroPositivo(sId)) {
                    try { id = std::stoi(sId); } catch (...) { id = -1; }
                    if (id >= 0) break;
                }
                std::cout << "ERROR. El ID debe contener solo dígitos.\n";
            }
            while (true) {  // Ingrese nombre con control de error
                std::cout << "Ingrese Nombre: ";
                std::getline(std::cin, nombre);
                if (Utilidades::esSoloLetrasEspacios(nombre)) break;
                std::cout << "ERROR. El nombre debe contener solo letras y espacios.\n";
            }
            while (true) {  // Ingrese apellido con control de error
                std::cout << "Ingrese Apellido: ";
                std::getline(std::cin, apellido);
                if (Utilidades::esSoloLetrasEspacios(apellido)) break;
                std::cout << "[Error] El apellido debe contener solo letras y espacios.\n";
            }
            while (true) {  // Ingrese carrera con control de error
                std::cout << "Ingrese Carrera: ";
                std::getline(std::cin, carrera);
                if (Utilidades::esSoloLetrasEspacios(carrera)) break;
                std::cout << "[Error] La carrera debe contener solo letras y espacios.\n";
            }
            while (true) {  // Ingrese fecha con control de error
                std::cout << "Ingrese Fecha de Ingreso (DD/MM/AAAA): ";
                std::cin >> fechaIngreso;
                if (Utilidades::fechaFormatoValido(fechaIngreso)) break;
                std::cout << "ERROR. La fecha debe estar en formato DD/MM/AAAA.\n";
            }

            Alumno nuevoAlumno(id, nombre, apellido, carrera, fechaIngreso);
            lista.agregarAlumno(nuevoAlumno);

        } else if (opcionAlumno == 2) {
            int id;
            std::cout << "Ingrese ID a buscar: ";
            std::cin >> id;
            NodoAlumno* encontrado = lista.buscarPorId(id);
            if (encontrado) {
                encontrado->dato.mostrar();
            } else {
                std::cout << "[Alumno no encontrado]\n";
            }

        } else if (opcionAlumno == 3) {
            std::string nombre;
            std::cout << "Ingrese nombre a buscar: ";
            std::cin >> nombre;
            lista.buscarPorNombre(nombre);

        } else if (opcionAlumno == 4) {
            int id;
            std::cout << "Ingrese ID a eliminar: ";
            std::cin >> id;
            if (lista.eliminarPorId(id)) {
                std::cout << "Alumno eliminado correctamente.\n";
            } else {
                std::cout << "[No existe un alumno con ese ID]\n";
            }

        }

    } while (opcionAlumno != 0);
}


// FUNCIÓN PARA MANEJO DE CURSOS
void menuManejoCursos(ListaCursos& cursos, ListaInscripciones& inscripciones) {
    int opcionCurso;
    do {
        std::cout << "\n=== Manejo de Cursos ===\n";
        std::cout << "1. Crear curso\n";
        std::cout << "2. Buscar curso por ID\n";
        std::cout << "3. Buscar curso por nombre\n";
        std::cout << "4. Eliminar curso por ID\n";
        std::cout << "5. Mostrar todos\n";
        std::cout << "0. Volver\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcionCurso;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida. Intente nuevamente.\n";
            opcionCurso = -1;
            continue;
        }

        if (opcionCurso == 1) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::string sId, nombre, sCantidadMax, carrera, profesor;
            int id = -1, cupo = -1;

            while (true) {
                std::cout << "ID: ";
                std::getline(std::cin, sId);
                if (Utilidades::esNumeroEnteroPositivo(sId)) {
                    try { id = std::stoi(sId); } catch (...) { id = -1; }
                    if (id >= 0) {
                        if (cursos.existeId(id)) {
                            std::cout << "ERROR. Ya existe un curso con ese ID.\n";
                        } else break;
                    }
                } else {
                    std::cout << "ERROR. Solo digitos.\n";
                }
            }

            while (true) {
                std::cout << "Nombre del curso: ";
                std::getline(std::cin, nombre);
                if (Utilidades::esSoloLetrasEspacios(nombre) && !nombre.empty()) break;
                std::cout << "ERROR. Solo letras y espacios.\n";
            }

            while (true) {
                std::cout << "Capacidad maxima: ";
                std::getline(std::cin, sCupo);
                if (Utilidades::esNumeroEnteroPositivo(sCupo)) {
                    try { cupo = std::stoi(sCupo); } catch (...) { cupo = -1; }
                    if (cupo >= 0) break;
                }
                std::cout << "ERROR. Ingrese entero positivo.\n";
            }

            while (true) {
                std::cout << "Carrera: ";
                std::getline(std::cin, carrera);
                if (Utilidades::esSoloLetrasEspacios(carrera) && !carrera.empty()) break;
                std::cout << "ERROR. Solo letras y espacios.\n";
            }

            while (true) {
                std::cout << "Profesor: ";
                std::getline(std::cin, profesor);
                if (Utilidades::esSoloLetrasEspacios(profesor) && !profesor.empty()) break;
                std::cout << "ERROR. Solo letras y espacios.\n";
            }

            Curso nuevo(id, nombre, cupo, carrera, profesor);
            cursos.agregarCurso(nuevo);
            std::cout << "Curso creado.\n";
        }
        else if (opcionCurso == 2) {
            int id;
            std::cout << "Ingrese ID del curso: ";
            std::cin >> id;
            auto* nodo = cursos.buscarPorCodigo(id);
            if (nodo) ListaCursos::mostrarCurso(nodo->dato);
            else std::cout << "[No existe un curso con ese ID]\n";
        }
        else if (opcionCurso == 3) {
            std::string nombre;
            std::cout << "Ingrese nombre a buscar: ";
            std::cin >> nombre;
            int mostrados = cursos.listarPorNombre(nombre);
            if (mostrados == 0) std::cout << "[Sin coincidencias por nombre]\n";
        }
        else if (opcionCurso == 4) {
            int id;
            std::cout << "Ingrese ID de curso a eliminar: ";
            std::cin >> id;
            if (cursos.eliminarPorId(id, inscripciones))
                std::cout << "Curso eliminado.\n";
            else
                std::cout << "[No existe un curso con ese ID]\n";
        }
        else if (opcionCurso == 5) {
            cursos.listarTodos();
        }

    } while (opcionCurso != 0);
}





