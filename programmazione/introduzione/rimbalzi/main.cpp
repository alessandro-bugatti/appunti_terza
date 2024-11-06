#include <iostream>

int main() {
    float H;
    int conta = 0;
    std::cout << "INserisci l'altezza in metri: ";
    std::cin >> H;
    while(H > 0.001) {
        H = H * 0.99;
        conta++;
    }
    std::cout << "Il numero di rimbalzi è " << conta << std::endl;
    return 0;
}
