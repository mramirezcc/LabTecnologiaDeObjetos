#ifndef PROFESOR_H
#define PROFESOR_H

#include "Persona.h"

class Profesor : public Persona {
private:
    std::string departamento;

public:
    Profesor();
    Profesor(const std::string& nombre, int edad, const std::string& departamento);
    
    std::string getDepartamento() const;
    void setDepartamento(const std::string& departamento);
    
    std::string toString() const override;
};

#endif