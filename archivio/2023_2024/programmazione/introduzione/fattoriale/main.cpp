#include <iostream>

int main() {
    int n;
    double fattoriale = 1;
    std::cout << "Inserire un numero: ";
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
       fattoriale *= i; // fattoriale = fattoriale * i;
    }
    std::cout << "Il fattoriale del numero e' " << fattoriale << std::endl;
    return 0;
}
