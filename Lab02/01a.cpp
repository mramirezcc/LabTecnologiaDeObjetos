#include <iostream>
#include <vector>

int countChange(int money, const std::vector<int>& coins, int n) {
    if (money == 0) return 1;
    if (money < 0) return 0;
    if (money > 0 && n <= 0) return 0;
    
    return countChange(money - coins[n - 1], coins, n) + countChange(money, coins, n - 1);
}

int main() {
    int money;
    std::cout << "Introduce la cantidad de dinero: ";
    std::cin >> money;
    
    std::vector<int> coins = {1, 2};
    
    std::cout << "Maneras de dar cambio para " << money << ": " << countChange(money, coins, coins.size()) << std::endl;
    
    return 0;
}
