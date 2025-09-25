#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
private:
    std::string nombre;
    int edad;

public:
    Persona();
    Persona(const std::string& nombre, int edad);
    
    // Getters y Setters
    std::string getNombre() const;
    void setNombre(const std::string& nombre);
    
    int getEdad() const;
    void setEdad(int edad);
    
    virtual std::string toString() const;
    virtual ~Persona() = default;
};

#endif