#include "Alumno.h"
#include <iostream>

Alumno::Alumno(int id, const std::string &nombre, const std::string &apellido, const std::string &carrera, const std::string &fecha_ingreso)
    : id_alumno_(id), nombre_(nombre), apellido_(apellido),
      carrera_(carrera), fecha_ingreso_(fecha_ingreso) {}

int Alumno::id_alumno() const { return id_alumno_; }
const std::string& Alumno::nombre() const { return nombre_; }
const std::string& Alumno::apellido() const { return apellido_; }
const std::string& Alumno::carrera() const { return carrera_; }
const std::string& Alumno::fecha_ingreso() const { return fecha_ingreso_; }

void Alumno::mostrar() const {
    std::cout << id_alumno_ << " - " << nombre_ << " " << apellido_
              << " (" << carrera_ << "), ingreso: " << fecha_ingreso_ << "\n";
}