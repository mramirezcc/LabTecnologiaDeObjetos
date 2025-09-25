#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Persona.h"

class Estudiante : public Persona {
private:
    std::string carrera;
    int semestre;

public:
    Estudiante();
    Estudiante(const std::string& nombre, int edad, const std::string& carrera, int semestre);
    
    std::string getCarrera() const;
    void setCarrera(const std::string& carrera);
    
    int getSemestre() const;
    void setSemestre(int semestre);
    
    std::string toString() const override;
};

#endif