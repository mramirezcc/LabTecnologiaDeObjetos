#include <iostream>

int hmsToS(int h, int m, int s){
    return 3600*h + 60*m + s;
}

int main(){
    int h, m, s;
    std::cout << "Ingrese el tiempo en formato hrs min seg : ";
    std::cin >> h >> m >> s;
    std::cout << "Tiempo equivalente en segundos: " << hmsToS(h, m, s) << "s\n";
}