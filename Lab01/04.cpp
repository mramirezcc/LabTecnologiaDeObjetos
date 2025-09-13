#include <iostream>

double min3(double a, double b, double c){
    if(a < b){
        if(a < c) return a;
        return c;
    }
    if(b < c) return b;
    return c;
}

int main(){
    double a, b, c;
    std::cout << "Ingrese 3 numeros decimales: ";
    std::cin >> a >> b >> c;
    std::cout << "El menor es " << min3(a, b, c) << std::endl;
}