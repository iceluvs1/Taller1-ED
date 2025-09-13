#include <iostream>
#include <limits>
#include <iomanip>
#include "Alumno.h"
#include "ListaAlumnos.h"
#include "NodoAlumno.h"
#include "Utilidades.h"
#include "ListaCursos.h"
#include "ListaInscripciones.h"


void menuManejoAlumnos(ListaAlumnos& lista);
void menuManejoCursos(ListaCursos& cursos, ListaInscripciones& inscripciones);
void menuManejoInscripciones(ListaInscripciones& inscripciones, ListaAlumnos& alumnos, ListaCursos& cursos);
void menuManejoNotas(ListaInscripciones& inscripciones);
void menuConsultasReportes(ListaAlumnos& alumnos, ListaCursos& cursos, ListaInscripciones& inscripciones);


int main() {
    ListaAlumnos alumnos;
    ListaCursos cursos;
    ListaInscripciones inscripciones;
    int opcion = -1;

    do {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Manejo de Alumnos\n";
        std::cout << "2. Manejo de Cursos\n";
        std::cout << "3. Manejo de Inscripciones\n";
        std::cout << "4. Manejo de Notas\n";
        std::cout << "5. Consultas y Reportes\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";

        if (!(std::cin >> opcion)) {
            std::cin.clear(); // limpia el error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida, intente de nuevo.\n";
            opcion = -1; // valor inválido para que no salga del menú
            continue;
        }

        switch (opcion) {
            case 1: {
                menuManejoAlumnos(alumnos);
                break;
            }
            case 2: {
                menuManejoCursos(cursos, inscripciones);
                break;
            }
            case 3: {
                menuManejoInscripciones(inscripciones, alumnos, cursos);
                break;
            }
            case 4: {
                menuManejoNotas(inscripciones);
                break;
            }
            case 5: {
                menuConsultasReportes(alumnos, cursos, inscripciones);
                break;
            }
            case 0:
                std::cout << "MENU CERRADO CON EXITO\n";
                break;
            default:
                std::cout << "Opcion invalida, intente de nuevo.\n";
                break;
        }



    }while (opcion != 0);
    return 0;
}


// FUNCIÓN PARA MANEJO DE ALUMNOS
void menuManejoAlumnos(ListaAlumnos& lista) {
    int opcionAlumno;
    do {
        std::cout << "\n>>> Manejo de Alumnos <<<\n";
        std::cout << "1. Crear alumno\n";
        std::cout << "2. Buscar alumno por ID\n";
        std::cout << "3. Buscar alumno por nombre\n";
        std::cout << "4. Eliminar alumno por ID\n";
        std::cout << "0. Volver al menu principal\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcionAlumno;

        // Manejar errores de entrada del usuario
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida, intente de nuevo.\n";
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
                std::cout << "ERROR. El ID debe contener solo digitos.\n";
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
        std::cout << "\n>>> Manejo de Cursos <<<\n";
        std::cout << "1. Crear curso\n";
        std::cout << "2. Buscar curso por ID\n";
        std::cout << "3. Buscar curso por nombre\n";
        std::cout << "4. Eliminar curso por ID\n";
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

            std::string sId, nombre, sCupo, carrera, profesor;
            int id = -1, cupo = -1;

            // ID
            while (true) {
                std::cout << "ID: ";
                std::getline(std::cin, sId);
                if (Utilidades::esNumeroEnteroPositivo(sId)) {
                    try { id = std::stoi(sId); } catch (...) { id = -1; }
                    if (id >= 0) {
                        if (cursos.buscarPorId(id)) {
                            std::cout << "ERROR. Ya existe un curso con ese ID.\n";
                        } else break;
                    }
                } else {
                    std::cout << "ERROR. Solo digitos.\n";
                }
            }

            // Nombre
            while (true) {
                std::cout << "Nombre del curso: ";
                std::getline(std::cin, nombre);
                if (Utilidades::esSoloLetrasEspacios(nombre) && !nombre.empty()) break;
                std::cout << "ERROR. Solo letras y espacios.\n";
            }

            // Capacidad
            while (true) {
                std::cout << "Capacidad maxima: ";
                std::getline(std::cin, sCupo);
                if (Utilidades::esNumeroEnteroPositivo(sCupo)) {
                    try { cupo = std::stoi(sCupo); } catch (...) { cupo = -1; }
                    if (cupo >= 0) break;
                }
                std::cout << "ERROR. Ingrese entero positivo.\n";
            }

            // Carrera
            while (true) {
                std::cout << "Carrera: ";
                std::getline(std::cin, carrera);
                if (Utilidades::esSoloLetrasEspacios(carrera) && !carrera.empty()) break;
                std::cout << "ERROR. Solo letras y espacios.\n";
            }

            // Profesor
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
            NodoCurso* nodo = cursos.buscarPorId(id);
            if (nodo) nodo->dato.mostrar();
            else std::cout << "[No existe un curso con ese ID]\n";
        }
        else if (opcionCurso == 3) {
            std::string nombre;
            std::cout << "Ingrese nombre a buscar: ";
            std::cin >> nombre;
            cursos.buscarPorNombre(nombre);
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

    } while (opcionCurso != 0);
}


// FUNCIÓN PARA MANEJO DE INSCRIPCIONES
void menuManejoInscripciones(ListaInscripciones& inscripciones, ListaAlumnos& alumnos, ListaCursos& cursos) {
    int opcionIns = -1;
    do {
        std::cout << "\n>>> Manejo de Inscripciones <<<\n";
        std::cout << "1. Inscribir alumno en curso\n";
        std::cout << "2. Eliminar alumno de curso\n";
        std::cout << "0. Volver\n";
        std::cout << "Seleccione una opcion: ";

        if (!(std::cin >> opcionIns)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida.\n";
            opcionIns = -1;
            continue;
        }

        if (opcionIns == 1) {
            int id_alumno, id_curso;
            while (true) {
                std::cout << "ID Alumno: ";
                if (std::cin >> id_alumno) break;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ERROR. Debe ingresar un número entero.\n";
            }
            while (true) {
                std::cout << "ID Curso : ";
                if (std::cin >> id_curso) break;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ERROR. Debe ingresar un número entero.\n";
            }

            inscripciones.inscribir(id_alumno, id_curso, alumnos, cursos);
        }

        else if (opcionIns == 2) {
            int id_alumno, id_curso;
            while (true) {
                std::cout << "ID Alumno: ";
                if (std::cin >> id_alumno) break;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ERROR. Debe ingresar un número entero.\n";
            }
            while (true) {
                std::cout << "ID Curso : ";
                if (std::cin >> id_curso) break;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ERROR. Debe ingresar un número entero.\n";
            }

            if (inscripciones.desinscribir(id_alumno, id_curso))
                std::cout << "Inscripción eliminada.\n";
            else
                std::cout << "[No existe esa inscripción]\n";
        }

    } while (opcionIns != 0);
}


// FUNCIÓN PARA MANEJO DE NOTAS
void menuManejoNotas(ListaInscripciones& inscripciones) {
    int opcionNotas = -1;
    do {
        std::cout << "\n>>> Manejo de Notas <<<\n";
        std::cout << "1. Agregar nota (1.0 a 7.0)\n";
        std::cout << "2. Ver notas de un alumno en un curso\n";
        std::cout << "0. Volver\n";
        std::cout << "Seleccione una opcion: ";

        if (!(std::cin >> opcionNotas)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida.\n";
            opcionNotas = -1;
            continue;
        }

        if (opcionNotas == 1) {
            int id_alumno, id_curso;
            float nota;
            while (true) {
                std::cout << "ID Alumno: ";
                if (std::cin >> id_alumno) break;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ERROR. Debe ingresar un numero entero.\n";
            }
            while (true) {
                std::cout << "ID Curso : ";
                if (std::cin >> id_curso) break;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ERROR. Debe ingresar un numero entero.\n";
            }
            while (true) {
                std::cout << "Nota (1.0 a 7.0): ";
                if (std::cin >> nota && nota >= 1.0f && nota <= 7.0f) break;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ERROR. La nota debe estar entre 1.0 y 7.0.\n";
            }

            inscripciones.agregarNota(id_alumno, id_curso, nota);
        }
        else if (opcionNotas == 2) {
            int id_alumno, id_curso;
            while (true) {
                std::cout << "ID Alumno: ";
                if (std::cin >> id_alumno) break;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ERROR. Debe ingresar un numero entero.\n";
            }
            while (true) {
                std::cout << "ID Curso : ";
                if (std::cin >> id_curso) break;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ERROR. Debe ingresar un numero entero.\n";
            }

            inscripciones.verNotas(id_alumno, id_curso);
        }

    } while (opcionNotas != 0);
}



//Complementos
static std::string nombreCompletoAlumno(const ListaAlumnos& alumnos, int id) {
    if (NodoAlumno* nodo = alumnos.buscarPorId(id)) {
        return nodo->dato.nombre() + " " + nodo->dato.apellido();
    }
    return "Desconocido";
}

static std::string nombreCurso(const ListaCursos& cursos, int id) {
    if (NodoCurso* nodo = cursos.buscarPorId(id)) {
        return nodo->dato.nombre_curso();
    }
    return "Desconocido";
}
// FUNCIÓN PARA CONSULTAS Y REPORTES
void menuConsultasReportes(ListaAlumnos& alumnos, ListaCursos& cursos, ListaInscripciones& inscripciones) {
    int op = -1;
    do {
        std::cout << "\n>>> Consultas y Reportes <<<\n";
        std::cout << "1. Obtener todos los alumnos de una carrera\n";
        std::cout << "2. Obtener todos los cursos en los que un alumno esta inscrito\n";
        std::cout << "3. Calcular el promedio de notas de un alumno en un curso\n";
        std::cout << "4. Calcular el promedio general de un alumno\n";
        std::cout << "0. Volver\n";
        std::cout << "Seleccione una opcion: ";

        if (!(std::cin >> op)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida.\n";
            op = -1;
            continue;
        }

        if (op == 1) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string carrera;
            std::cout << "Carrera: ";
            std::getline(std::cin, carrera);
            alumnos.listarPorCarrera(carrera);
        }
        else if (op == 2) {
            int id_alumno;
            while (true) {
                std::cout << "ID Alumno: ";
                if (std::cin >> id_alumno) break;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ERROR. Debe ingresar un numero entero.\n";
            }
            inscripciones.listarCursosDeAlumno(id_alumno, cursos);
        }
        else if (op == 3) {
            int id_alumno, id_curso;
            while (true) {
                std::cout << "ID Alumno: ";
                if (std::cin >> id_alumno) break;
                std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ERROR. Debe ingresar un numero entero.\n";
            }
            while (true) {
                std::cout << "ID Curso : ";
                if (std::cin >> id_curso) break;
                std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ERROR. Debe ingresar un numero entero.\n";
            }
            float promedioCurso = 0.0f;
            if (inscripciones.promedioAlumnoEnCurso(id_alumno, id_curso, promedioCurso)) {
                std::cout << "Promedio de " << nombreCompletoAlumno(alumnos, id_alumno) << " en " << nombreCurso(cursos, id_curso) << " = " << std::fixed << std::setprecision(2) << promedioCurso << "\n";
            } else {
                std::cout << "[No hay notas registradas o no existe la inscripcion]\n";
            }
        }
        else if (op == 4) {
            int id_alumno;
            while (true) {
                std::cout << "ID Alumno: ";
                if (std::cin >> id_alumno) break;
                std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ERROR. Debe ingresar un numero entero.\n";
            }
            float promedioGeneral = 0.0f;
            if (inscripciones.promedioGeneralAlumno(id_alumno, promedioGeneral)) {
                std::cout << "Promedio General de " << nombreCompletoAlumno(alumnos, id_alumno) << " = " << std::fixed << std::setprecision(2) << promedioGeneral << "\n";
            } else {
                std::cout << "[El alumno no tiene cursos con notas registradas]\n";
            }
        }

    } while (op != 0);
}