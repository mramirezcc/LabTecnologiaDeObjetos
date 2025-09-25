#ifndef HORARIO_H
#define HORARIO_H

#include <string>

class Horario {
private:
    std::string dia;
    std::string horaInicio;
    std::string horaFin;

public:
    Horario();
    Horario(const std::string& dia, const std::string& horaInicio, const std::string& horaFin);
    
    std::string getDia() const;
    void setDia(const std::string& dia);
    
    std::string getHoraInicio() const;
    void setHoraInicio(const std::string& horaInicio);
    
    std::string getHoraFin() const;
    void setHoraFin(const std::string& horaFin);
    
    std::string toString() const;
};

#endif