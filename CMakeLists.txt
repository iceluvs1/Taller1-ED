cmake_minimum_required(VERSION 3.26)
project(Taller1)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)

add_executable(Taller1 main.cpp
        Alumno.h
        Alumno.cpp
        Curso.cpp
        Curso.h
)
