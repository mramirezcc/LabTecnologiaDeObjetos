#include "Profesor.h"
#include <sstream>

Profesor::Profesor() : Persona(), departamento("") {}

Profesor::Profesor(const std::string& nombre, int edad, const std::string& departamento)
    : Persona(nombre, edad), departamento(departamento) {}

std::string Profesor::getDepartamento() const {
    return departamento;
}

void Profesor::setDepartamento(const std::string& departamento) {
    this->departamento = departamento;
}

std::string Profesor::toString() const {
    std::stringstream ss;
    ss << Persona::toString() << ", Departamento: " << departamento << " (Profesor)";
    return ss.str();
}