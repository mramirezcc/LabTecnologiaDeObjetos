#include <iostream>

int main(){
    int myArr[10];
    for(int i = 0; i < 10; i++){

        std::cout << "Ingrese un numero";
        if(i > 0)
            std::cout << " mayor a " << myArr[i-1];
        std::cout << ": ";
        
        int newNum;
        std::cin >> newNum;
        if(i > 0)
            while(newNum <= myArr[i-1]){
                std::cout << "Intente de nuevo... (Mayor a " << myArr[i-1] << ")\n";
                std::cin >> newNum;
            }
        myArr[i] = newNum;
    }

    //Mostrar los numeros guardados
    std::cout << "[";
    for(int i = 0; i < 10; i++){
        std::cout << myArr[i];
        if(i < 9) std::cout << ", ";
    }
    std::cout << "]\n"; 
    
}