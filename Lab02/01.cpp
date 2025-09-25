#include <iostream>
#include <string>

void countChangeAux(int money, int* list, int listSize, int curIdx, std::string curStr){
    if(money == 0){
        std::cout << curStr << std::endl;
        return;
    }
    if(curIdx == listSize || money < 0)
        return;
    
    std::string newStr = (curStr == "" ? curStr : curStr + " + ") + std::to_string(list[curIdx]);
    // Usar esta moneda
    countChangeAux(money - list[curIdx], list, listSize, curIdx, newStr);
    // Saltar esta moneda
    countChangeAux(money, list, listSize, curIdx + 1, curStr);
}

void countChange(int money, int* list, int listSize){
    countChangeAux(money, list, listSize, 0, "");
}

int main() {
    int list[] = {1, 2, 5};
    int listSize = sizeof(list)/sizeof(int);

    int money;
    std::cout << "Ingrese el monto: ";
    std::cin >> money;

    countChange(money, list, listSize);

}