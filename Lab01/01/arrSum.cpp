#include <iostream>

int sumarArreglo(int arr[], int tamanio){
    int res = 0;
    for(int i = 0; i < tamanio; i++){
        res += arr[i];
    }
    return res;
}

int sumarArregloDinamico(int* arr, int tamanio){
    int res = 0;
    for(int i = 0; i < tamanio; i++){
        res += arr[i];
    }
    return res;
}

int main(){
    int myArr[] = {1, 2, 3, 4, 5};
    int suma = sumarArreglo(myArr, 5);
    std::cout << "La suma es: " << suma << std::endl;

    int tam = 5;
    int* myArrDin = new int[tam];
    for(int i = 0; i < tam ; i++){
        myArrDin[i] += i + 1;
    }
    int suma2 = sumarArregloDinamico(myArrDin, tam);
    std::cout << "La suma del arreglo dinamico es: " << suma2 << std::endl;
}