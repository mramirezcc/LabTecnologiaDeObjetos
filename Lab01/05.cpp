#include <iostream>

double calcularCargo(int hrs){
    if(hrs <= 1) return 3.0 * hrs;
    return 3.0 + (0.5 * (hrs - 1));
}

int main(){
    int hrs;
    std::cout << "Ingrese el numero de horas transcurridas: ";
    std::cin >> hrs;
    std::cout << "El cargo es de S/" << calcularCargo(hrs) << std::endl;
}