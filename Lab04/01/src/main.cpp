#include "VentanaColores.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // Crear y mostrar la ventana principal
    VentanaColores ventana;
    ventana.show();
    
    // Ejecutar el bucle principal de la aplicación
    return app.exec();
}