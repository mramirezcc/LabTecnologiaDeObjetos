#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H

#include "Curso.h"
#include <vector>

class Universidad {
private:
    std::string nombre;
    std::vector<Curso*> cursos;  // Agregación

public:
    Universidad();
    Universidad(const std::string& nombre);
    
    std::string getNombre() const;
    void setNombre(const std::string& nombre);
    
    void agregarCurso(Curso* curso);
    void listarCursos() const;
    
    std::string toString() const;
};

#endif