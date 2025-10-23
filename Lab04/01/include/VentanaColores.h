#ifndef VENTANACOLORES_H
#define VENTANACOLORES_H

#include <QMainWindow>
#include <QListWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

class VentanaColores : public QMainWindow
{
    Q_OBJECT  // Necesario para señales y slots

public:
    VentanaColores(QWidget *parent = nullptr);
    ~VentanaColores();

private slots:
    // Slot que se ejecutará cuando se seleccione un color
    void onColorSeleccionado(QListWidgetItem *item);

private:
    void setupUI();
    void setupColores();
    
    // Componentes de la interfaz
    QWidget *centralWidget;
    QVBoxLayout *layout;
    QListWidget *listaColores;
    QLabel *labelColorSeleccionado;
};

#endif