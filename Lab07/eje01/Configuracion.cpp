#include <iostream>
#include <string>

class Configuracion {
private:
    std::string idioma;
    std::string zonaHoraria;
    
    // constructor privado
    Configuracion() : idioma("español"), zonaHoraria("UTC-5") {}
    
    // prevenir copias
    Configuracion(const Configuracion&) = delete;
    void operator=(const Configuracion&) = delete;

public:
    // metodo para obtener la instancia unica
    static Configuracion& getInstance() {
        static Configuracion instancia;
        return instancia;
    }
    
    void mostrar_configuracion() {
        std::cout << "Idioma: " << idioma << std::endl;
        std::cout << "Zona Horaria: " << zonaHoraria << std::endl;
        std::cout << "Dirección: " << this << std::endl << std::endl;
    }
    
    // setters
    void setIdioma(const std::string& nuevoIdioma) {
        idioma = nuevoIdioma;
    }
    
    void setZonaHoraria(const std::string& nuevaZona) {
        zonaHoraria = nuevaZona;
    }
};

int main() {
    // Obtenemos varias referencias a la misma instancia
    Configuracion& config1 = Configuracion::getInstance();
    Configuracion& config2 = Configuracion::getInstance();
    Configuracion& config3 = Configuracion::getInstance();
    
    std::cout << "=== Configuraciones iniciales ===" << std::endl;
    config1.mostrar_configuracion();
    config2.mostrar_configuracion();
    config3.mostrar_configuracion();
    
    std::cout << "=== Cambiando configuración ===" << std::endl;
    config1.setIdioma("inglés");
    config1.setZonaHoraria("UTC+0");
    
    std::cout << "=== Configuraciones después del cambio ===" << std::endl;
    config1.mostrar_configuracion();
    config2.mostrar_configuracion();
    config3.mostrar_configuracion();
    
    return 0;
}