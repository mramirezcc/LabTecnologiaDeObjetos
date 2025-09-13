#include <iostream>
#include <cstdlib>
#include <ctime>

const int CARAS = 6;
const int N = 20000;

int lanzarDado() {
    return rand() % CARAS + 1;
}

int main() {
    srand(time(nullptr));
    
    // Inicializado en 0 por si hay datos basura
    int arr[CARAS] = {0};
    
    for(int i = 0; i < N; i++) {
        int res = lanzarDado();
        arr[res - 1]++;
    }
    
    std::cout << "Cara\tFrec.\tPorcentaje\n";
    for(int i = 0; i < CARAS; i++) {
        std::cout << i + 1 << "\t" << arr[i] << "\t" << arr[i]*100.0/N << "%" << std::endl;
    }
    
    return 0;
}