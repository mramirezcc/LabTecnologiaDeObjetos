#include "Universidad.h"
#include <iostream>
#include <sstream>

Universidad::Universidad() : nombre("") {}

Universidad::Universidad(const std::string& nombre) : nombre(nombre) {}

std::string Universidad::getNombre() const {
    return nombre;
}

void Universidad::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Universidad::agregarCurso(Curso* curso) {
    cursos.push_back(curso);
}

void Universidad::listarCursos() const {
    std::cout << "\n--- Cursos de la Universidad " << nombre << " ---\n";
    for (size_t i = 0; i < cursos.size(); ++i) {
        std::cout << (i + 1) << ". " << cursos[i]->toString() << "\n\n";
    }
}

std::string Universidad::toString() const {
    std::stringstream ss;
    ss << "Universidad: " << nombre << "\n";
    ss << "Número de cursos: " << cursos.size();
    return ss.str();
}