#pragma once
#include<iostream>


class Alumno {
private:
    int id_alumno_;
    std::string nombre_;
    std:: string apellido_;
    std:: string carrera_;
    std:: string fecha_ingreso_;

public:
    // Constructor
    Alumno(int id_alumno, const std::string &nombre, const std::string &apellido, const std::string &carrera, const std::string &fecha_ingreso);

    // Getters
    int id_alumno() const;
    const std::string& nombre() const;
    const std::string& apellido() const;
    const std::string& carrera() const;
    const std::string& fecha_ingreso() const;

    // Función
    void mostrar() const;
};
