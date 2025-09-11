#include <iostream>

int main(){
    int myArr[10];
    for(int i = 0; i < 10; i++){

        std::cout << "Ingrese un numero";
        if(i > 0)
            std::cout << "mayor a " << myArr[i-1];
        std::cout << ": ";
        
        int newNum;
        std::cin >> newNum;
        if(i > 0)
            while(newNum <= myArr[i-1]){
                std::cout << "Intente de nuevo...\n";
                std::cin >> newNum;
            }
        myArr[i] = newNum;
    }
    
}