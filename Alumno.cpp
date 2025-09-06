#include "Alumno.h"
#include <iostream>

Alumno::Alumno(int id, const std::string &nombre, const std::string &apellido, const std::string &carrera, const std::string &fecha_ingreso)
    : id_alumno_(id), nombre_(nombre), apellido_(apellido),
      carrera_(carrera), fechaIngreso_(fecha_ingreso) {}

int Alumno::id_alumno() const { return id_alumno_; }
const std::string& Alumno::nombre() const { return nombre_; }
const std::string& Alumno::apellido() const { return apellido_; }
const std::string& Alumno::carrera() const { return carrera_; }
const std::string& Alumno::fechaIngreso() const { return fechaIngreso_; }

void Alumno::mostrar() const {
    std::cout << "ID: " << id_alumno()
              << " | Nombre: " << nombre()
              << " " << apellido()
              << " | Carrera: " << carrera()
              << " | Ingreso: " << fechaIngreso()
              << std::endl;
}