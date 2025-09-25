#ifndef REPORTE_H
#define REPORTE_H

#include "Estudiante.h"
#include <string>

class Reporte {
public:
    // Dependencia: el reporte depende temporalmente de un estudiante
    static std::string generarReporte(const Estudiante& estudiante);
};

#endif