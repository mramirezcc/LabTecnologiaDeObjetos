#include "Estudiante.h"
#include <sstream>

Estudiante::Estudiante() : Persona(), carrera(""), semestre(0) {}

Estudiante::Estudiante(const std::string& nombre, int edad, const std::string& carrera, int semestre)
    : Persona(nombre, edad), carrera(carrera), semestre(semestre) {}

std::string Estudiante::getCarrera() const {
    return carrera;
}

void Estudiante::setCarrera(const std::string& carrera) {
    this->carrera = carrera;
}

int Estudiante::getSemestre() const {
    return semestre;
}

void Estudiante::setSemestre(int semestre) {
    this->semestre = semestre;
}

std::string Estudiante::toString() const {
    std::stringstream ss;
    ss << Persona::toString() << ", Carrera: " << carrera 
       << ", Semestre: " << semestre << " (Estudiante)";
    return ss.str();
}