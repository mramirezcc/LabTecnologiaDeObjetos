#include "Horario.h"
#include <sstream>

Horario::Horario() : dia(""), horaInicio(""), horaFin("") {}

Horario::Horario(const std::string& dia, const std::string& horaInicio, const std::string& horaFin)
    : dia(dia), horaInicio(horaInicio), horaFin(horaFin) {}

std::string Horario::getDia() const {
    return dia;
}

void Horario::setDia(const std::string& dia) {
    this->dia = dia;
}

std::string Horario::getHoraInicio() const {
    return horaInicio;
}

void Horario::setHoraInicio(const std::string& horaInicio) {
    this->horaInicio = horaInicio;
}

std::string Horario::getHoraFin() const {
    return horaFin;
}

void Horario::setHoraFin(const std::string& horaFin) {
    this->horaFin = horaFin;
}

std::string Horario::toString() const {
    std::stringstream ss;
    ss << dia << " de " << horaInicio << " a " << horaFin;
    return ss.str();
}