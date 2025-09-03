#include <iostream>
#include "Alumno.h"

int main() {
    Alumno juan(1, "Juan", "Perez", "Ingeniero", "2020");
    juan.mostrar();


    int opcion;

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

        switch (opcion) {
            case 1: {

            }
            case 0:
                std::cout << "MENÚ CERRADO CON ÉXITO\n";
                break;
            default:
                std::cout << "Opción inválida, intente de nuevo.\n";
                break;
        }



    }while (opcion != 5);
    return 0;
}





