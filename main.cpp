#include <iostream>
#include <limits>
#include "Alumno.h"
#include "ListaAlumnos.h"
#include "NodoAlumno.h"


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
            int id;
            std::string nombre, apellido, carrera, fechaIngreso;

            std::cout << "Ingrese ID: ";
            std::cin >> id;
            std::cout << "Ingrese Nombre: ";
            std::cin >> nombre;
            std::cout << "Ingrese Apellido: ";
            std::cin >> apellido;
            std::cout << "Ingrese Carrera: ";
            std::cin >> carrera;
            std::cout << "Ingrese Fecha de Ingreso (DD/MM/AAAA): ";
            std::cin >> fechaIngreso;

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





