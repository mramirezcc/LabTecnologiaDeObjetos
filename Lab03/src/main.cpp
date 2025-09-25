#include <iostream>
#include "Profesor.h"
#include "Estudiante.h"
#include "Curso.h"
#include "Universidad.h"
#include "Reporte.h"

int main() {
    std::cout << "=== SISTEMA UNIVERSITARIO ===\n\n";
    
    // Crear 2 profesores
    Profesor prof1("Dr. Juan Pérez", 45, "Matemáticas");
    Profesor prof2("Dra. María García", 38, "Informática");
    
    std::cout << "Profesores creados:\n";
    std::cout << "1. " << prof1.toString() << "\n";
    std::cout << "2. " << prof2.toString() << "\n\n";
    
    // Crear 3 estudiantes
    Estudiante est1("Carlos López", 20, "Ingeniería Informática", 3);
    Estudiante est2("Ana Martínez", 22, "Matemáticas", 5);
    Estudiante est3("Pedro Sánchez", 19, "Física", 2);
    
    std::cout << "Estudiantes creados:\n";
    std::cout << "1. " << est1.toString() << "\n";
    std::cout << "2. " << est2.toString() << "\n";
    std::cout << "3. " << est3.toString() << "\n\n";
    
    // Crear horarios (composición con cursos)
    Horario horario1("Lunes y Miércoles", "08:00", "10:00");
    Horario horario2("Martes y Jueves", "14:00", "16:00");
    
    // Crear 2 cursos (cada uno con su horario)
    Curso curso1("Programación Avanzada", "INF-301", horario1, &prof2);
    Curso curso2("Cálculo Diferencial", "MAT-201", horario2, &prof1);
    
    std::cout << "Cursos creados:\n";
    std::cout << "1. " << curso1.toString() << "\n\n";
    std::cout << "2. " << curso2.toString() << "\n\n";
    
    // Crear universidad y agregar cursos (agregación)
    Universidad uni("Universidad Nacional");
    uni.agregarCurso(&curso1);
    uni.agregarCurso(&curso2);
    
    std::cout << uni.toString() << "\n";
    uni.listarCursos();
    
    // Generar reporte de un estudiante (dependencia)
    std::cout << "\n=== GENERANDO REPORTE ===\n";
    std::string reporte = Reporte::generarReporte(est1);
    std::cout << reporte << "\n";
    
    // Demostración de que los cursos pueden existir fuera de la universidad
    std::cout << "=== DEMOSTRACIÓN DE AGREGACIÓN ===\n";
    std::cout << "El curso '" << curso1.getNombre() << "' existe independientemente de la universidad.\n";
    std::cout << "Horario: " << curso1.getHorario().toString() << "\n";
    
    return 0;
}