#ifndef CURSO_H
#define CURSO_H

#include "Horario.h"
#include "Profesor.h"
#include <string>

class Curso {
private:
    std::string nombre;
    std::string codigo;
    Horario horario;  // Composición
    Profesor* profesor;  // Asociación

public:
    Curso();
    Curso(const std::string& nombre, const std::string& codigo, const Horario& horario, Profesor* profesor);
    
    std::string getNombre() const;
    void setNombre(const std::string& nombre);
    
    std::string getCodigo() const;
    void setCodigo(const std::string& codigo);
    
    Horario getHorario() const;
    void setHorario(const Horario& horario);
    
    Profesor* getProfesor() const;
    void setProfesor(Profesor* profesor);
    
    std::string toString() const;
};

#endif