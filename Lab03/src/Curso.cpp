#include "Curso.h"
#include <sstream>

Curso::Curso() : nombre(""), codigo(""), horario(), profesor(nullptr) {}

Curso::Curso(const std::string& nombre, const std::string& codigo, const Horario& horario, Profesor* profesor)
    : nombre(nombre), codigo(codigo), horario(horario), profesor(profesor) {}

std::string Curso::getNombre() const {
    return nombre;
}

void Curso::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

std::string Curso::getCodigo() const {
    return codigo;
}

void Curso::setCodigo(const std::string& codigo) {
    this->codigo = codigo;
}

Horario Curso::getHorario() const {
    return horario;
}

void Curso::setHorario(const Horario& horario) {
    this->horario = horario;
}

Profesor* Curso::getProfesor() const {
    return profesor;
}

void Curso::setProfesor(Profesor* profesor) {
    this->profesor = profesor;
}

std::string Curso::toString() const {
    std::stringstream ss;
    ss << "Curso: " << nombre << " (" << codigo << ")\n";
    ss << "Horario: " << horario.toString() << "\n";
    if (profesor != nullptr) {
        ss << "Profesor: " << profesor->getNombre();
    } else {
        ss << "Profesor: No asignado";
    }
    return ss.str();
}