#pragma once
#include <iostream>

class Curso {
private:
    int id_curso_;
    std::string nombre_curso_;
    int cantidad_max_;
    std::string carrera_curso_;
    std::string nombre_profesor_curso_;

public:
    // Constructor
    Curso(int id_curso, const std::string &nombre_curso, int cantidad_max, const std::string &carrera_curso, const std::string &nombre_profesor_curso);

    // Getters
    int id_curso() const;
    const std::string& nombre_curso() const;
    int cantidad_max() const;
    const std::string& carrera_curso() const;
    const std::string& nombre_profesor_curso() const;

    void mostrar() const;
};


