#include "Reporte.h"
#include <sstream>
#include <ctime>

std::string Reporte::generarReporte(const Estudiante& estudiante) {
    // Obtener fecha y hora actual
    time_t ahora = time(nullptr);
    char fechaHora[100];
    strftime(fechaHora, sizeof(fechaHora), "%Y-%m-%d %H:%M:%S", localtime(&ahora));
    
    std::stringstream ss;
    ss << "=== REPORTE TEMPORAL ===\n";
    ss << "Fecha y hora: " << fechaHora << "\n";
    ss << "Datos del estudiante:\n";
    ss << estudiante.toString() << "\n";
    ss << "=== FIN DEL REPORTE ===\n";
    
    return ss.str();
}