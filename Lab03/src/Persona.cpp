#include "Persona.h"
#include <sstream>

Persona::Persona() : nombre(""), edad(0) {}

Persona::Persona(const std::string& nombre, int edad) 
    : nombre(nombre), edad(edad) {}

std::string Persona::getNombre() const {
    return nombre;
}

void Persona::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

int Persona::getEdad() const {
    return edad;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

std::string Persona::toString() const {
    std::stringstream ss;
    ss << "Nombre: " << nombre << ", Edad: " << edad;
    return ss.str();
}