#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

class ConexionBD {
private:
    static ConexionBD* instancia;
    static mutex mutex_;
    bool conectado;

    // Constructor privado
    ConexionBD() : conectado(false) {
        cout << ">>> Creando objeto ConexionBD..." << endl;
    }

    // Prevenir copias
    ConexionBD(const ConexionBD&) = delete;
    ConexionBD& operator=(const ConexionBD&) = delete;

public:
    // Método estático para obtener la instancia (THREAD-SAFE)
    static ConexionBD* getInstancia() {
        lock_guard<mutex> lock(mutex_);
        
        if (instancia == nullptr) {
            instancia = new ConexionBD();
        }
        return instancia;
    }

    void conectar() {
        lock_guard<mutex> lock(mutex_);
        
        if (!conectado) {
            conectado = true;
            cout << "Conexión establecida." << endl;
        } else {
            cout << "Ya existe una conexión activa." << endl;
        }
    }

    void desconectar() {
        lock_guard<mutex> lock(mutex_);
        
        if (conectado) {
            conectado = false;
            cout << "Conexión cerrada." << endl;
        } else {
            cout << "No hay conexión para cerrar." << endl;
        }
    }

    void estado() {
        lock_guard<mutex> lock(mutex_);
        
        cout << (conectado ? "Estado: Conectado" : "Estado: Desconectado") << endl;
    }

    // Método para limpiar la instancia
    static void reset() {
        lock_guard<mutex> lock(mutex_);
        if (instancia != nullptr) {
            delete instancia;
            instancia = nullptr;
            cout << ">>> Instancia reseteada para pruebas." << endl;
        }
    }
};

// Inicialización de miembros estáticos
ConexionBD* ConexionBD::instancia = nullptr;
mutex ConexionBD::mutex_;

// Función que simula el comportamiento de un hilo
void simularHilo(int idHilo) {
    this_thread::sleep_for(chrono::milliseconds(idHilo * 50));
    
    ConexionBD* conexion = ConexionBD::getInstancia();
    
    cout << "--- Hilo " << idHilo << " iniciado ---" << endl;
    
    switch(idHilo % 4) {
        case 0:
            cout << "Hilo " << idHilo << " intentando conectar..." << endl;
            conexion->conectar();
            break;
        case 1:
            cout << "Hilo " << idHilo << " consultando estado..." << endl;
            conexion->estado();
            break;
        case 2:
            cout << "Hilo " << idHilo << " intentando desconectar..." << endl;
            conexion->desconectar();
            break;
        case 3:
            cout << "Hilo " << idHilo << " verificando instancia..." << endl;
            conexion->estado();
            break;
    }
    
    cout << "--- Hilo " << idHilo << " finalizado ---" << endl;
}

// Función para demostrar el problema 
void demostrarProblemaSinThreadSafe() {
    cout << "\nDEMOSTRACIÓN DEL PROBLEMA SIN THREAD-SAFE" << endl;
    cout << "===========================================" << endl;
    
    // condición de carrera
    cout << "Si múltiples hilos llegan a getInstancia() simultáneamente:" << endl;
    cout << "- Hilo 1: verifica instancia == null ✓" << endl;
    cout << "- Hilo 2: verifica instancia == null ✓" << endl;
    cout << "- Hilo 1: crea instancia A" << endl;
    cout << "- Hilo 2: crea instancia B" << endl;
    cout << "> RESULTADO: ¡Múltiples instancias creadas!" << endl;
}

int main() {
    cout << "INICIANDO DEMOSTRACIÓN SINGLETON THREAD-SAFE EN C++" << endl;
    cout << "=====================================================" << endl;
    
    // Primero demostramos el problema teórico
    demostrarProblemaSinThreadSafe();
    
    // PRUEBA ORIGINAL
    cout << "\nPRUEBA ORIGINAL DEL EJERCICIO 3" << endl;
    cout << "=================================" << endl;
    
    ConexionBD* c1 = ConexionBD::getInstancia();
    c1->conectar();
    c1->estado();

    ConexionBD* c2 = ConexionBD::getInstancia();
    c2->estado();

    if (c1 == c2) {
        cout << "✓ Ambas referencias apuntan a la misma instancia." << endl;
    } else {
        cout << "✗ ERROR: Las referencias son diferentes!" << endl;
    }

    c2->desconectar();
    
    // NUEVA PRUEBA
    cout << "\nPRUEBA MULTIHILO THREAD-SAFE" << endl;
    cout << "===============================" << endl;
    cout << "Creando 6 hilos que acceden concurrentemente..." << endl;
    
    const int NUM_HILOS = 6;
    vector<thread> hilos;
    
    // Crear múltiples hilos que acceden concurrentemente
    for (int i = 1; i <= NUM_HILOS; ++i) {
        hilos.emplace_back(simularHilo, i);
    }
    
    // Esperar a que todos los hilos terminen
    for (auto& hilo : hilos) {
        hilo.join();
    }
    
    // VERIFICACIÓN FINAL DE INTEGRIDAD
    cout << "\nVERIFICACIÓN FINAL DE INTEGRIDAD" << endl;
    cout << "=================================" << endl;
    
    ConexionBD* conexionFinal = ConexionBD::getInstancia();
    cout << "Estado final de la conexión: ";
    conexionFinal->estado();
    
    // Verificar que todas las referencias son iguales
    ConexionBD* test1 = ConexionBD::getInstancia();
    ConexionBD* test2 = ConexionBD::getInstancia();
    ConexionBD* test3 = ConexionBD::getInstancia();
    
    if (test1 == test2 && test2 == test3) {
        cout << "✓ TODAS las referencias son IDÉNTICAS - Singleton funciona correctamente" << endl;
    } else {
        cout << "✗ ERROR: Las referencias no son consistentes" << endl;
    }
    
    // 🧹 Limpieza final
    cout << "\nLIMPIEZA FINAL" << endl;
    cout << "=================" << endl;
    ConexionBD::reset();
    
    cout << "\nDEMOSTRACIÓN COMPLETADA EXITOSAMENTE" << endl;
    cout << "======================================" << endl;
    cout << "Resumen de características thread-safe implementadas:" << endl;
    cout << "✓ std::mutex para exclusión mutua" << endl;
    cout << "✓ std::lock_guard para RAII automático" << endl;
    cout << "✓ Sincronización en todos los métodos" << endl;
    cout << "✓ Prevención de copias con = delete" << endl;
    cout << "✓ Inicialización segura en entornos multihilo" << endl;
    
    return 0;
}