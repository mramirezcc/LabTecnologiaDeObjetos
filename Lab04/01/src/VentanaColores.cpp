#include "VentanaColores.h"
#include <QStringList>

VentanaColores::VentanaColores(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    setupColores();
    
    // Conectar la señal del QListWidget al slot
    connect(listaColores, &QListWidget::itemClicked, 
            this, &VentanaColores::onColorSeleccionado);
}

VentanaColores::~VentanaColores()
{
    // Los objetos QObject se destruyen automáticamente
}

void VentanaColores::setupUI()
{
    // Configurar ventana principal
    setWindowTitle("Selector de Colores");
    setFixedSize(300, 400);
    
    // Crear widget central y layout
    centralWidget = new QWidget(this);
    layout = new QVBoxLayout(centralWidget);
    
    // Crear lista de colores
    listaColores = new QListWidget(centralWidget);
    listaColores->setSelectionMode(QListWidget::SingleSelection);
    
    // Crear label para mostrar el color seleccionado
    labelColorSeleccionado = new QLabel("Selecciona un color", centralWidget);
    labelColorSeleccionado->setAlignment(Qt::AlignCenter);
    labelColorSeleccionado->setStyleSheet("font-size: 16px; font-weight: bold; padding: 10px;");
    
    // Añadir componentes al layout
    layout->addWidget(listaColores);
    layout->addWidget(labelColorSeleccionado);
    
    // Establecer widget central
    setCentralWidget(centralWidget);
}

void VentanaColores::setupColores()
{
    // Lista de colores
    QStringList colores = {
        "Rojo", "Azul", "Verde", "Amarillo", "Naranja",
        "Morado", "Rosa", "Marrón", "Negro", "Blanco",
        "Gris", "Turquesa", "Oro", "Plateado", "Bronce"
    };
    
    // Añadir colores a la lista
    listaColores->addItems(colores);
}

void VentanaColores::onColorSeleccionado(QListWidgetItem *item)
{
    // Este slot se ejecuta cuando se hace clic en un elemento de la lista
    QString color = item->text();
    
    // Actualizar el label con el color seleccionado
    labelColorSeleccionado->setText("Color seleccionado: " + color);
    
    // Cambiar el color del texto según el color seleccionado
    QString estilo = "font-size: 16px; font-weight: bold; padding: 10px;";
    
    if (color == "Rojo") {
        estilo += "color: red;";
    } else if (color == "Azul") {
        estilo += "color: blue;";
    } else if (color == "Verde") {
        estilo += "color: green;";
    } else if (color == "Amarillo") {
        estilo += "color: yellow; background-color: black;";
    } else if (color == "Naranja") {
        estilo += "color: orange;";
    } else if (color == "Morado") {
        estilo += "color: purple;";
    } else if (color == "Rosa") {
        estilo += "color: pink;";
    } else if (color == "Marrón") {
        estilo += "color: brown;";
    } else if (color == "Negro") {
        estilo += "color: black;";
    } else if (color == "Blanco") {
        estilo += "color: white; background-color: black;";
    } else if (color == "Gris") {
        estilo += "color: gray;";
    } else if (color == "Turquesa") {
        estilo += "color: turquoise;";
    } else if (color == "Oro") {
        estilo += "color: gold;";
    } else if (color == "Plateado") {
        estilo += "color: silver;";
    } else if (color == "Bronce") {
        estilo += "color: #CD7F32;"; // Código hexadecimal para bronce
    }
    
    labelColorSeleccionado->setStyleSheet(estilo);
}