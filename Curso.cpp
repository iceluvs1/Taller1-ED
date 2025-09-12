#include "Curso.h"
#include <iostream>
#include <iostream>


Curso::Curso(int id_curso, const std::string &nombre_curso, int cantidad_max, const std::string &carrera_curso, const std::string &nombre_profesor_curso)
    : id_curso_(id_curso), nombre_curso_(nombre_curso), cantidad_max_(cantidad_max),
      carrera_curso_(carrera_curso),
      nombre_profesor_curso_(nombre_profesor_curso) {}

int Curso::id_curso() const { return id_curso_; }
const std::string& Curso::nombre_curso() const { return nombre_curso_; }
int Curso::cantidad_max() const { return cantidad_max_; }
const std::string& Curso::carrera_curso() const { return carrera_curso_; }
const std::string& Curso::nombre_profesor_curso() const { return nombre_profesor_curso_; }

void Curso::mostrar() const {
    std::cout << "ID: " << id_curso()
              << " | Nombre: " << nombre_curso()
              << " | Cupos: " << cantidad_max()
              << " | Carrera: " << carrera_curso()
              << " | Profesor: " << nombre_profesor_curso()
              << std::endl;
}