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





