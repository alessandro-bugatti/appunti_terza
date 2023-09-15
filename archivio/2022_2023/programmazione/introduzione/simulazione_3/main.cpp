#include <iostream>

int main() {
    int n, somma = 0;
    std::cout << "Inserisca il numero: ";
    std::cin >> n;
    for (int i = 2; i < n; i += 2) {
        std::cout << i * i << std::endl;
        somma += i * i;
    }
    for (int i = 1; i < n; i += 2) {
        std::cout << i * i * i<< std::endl;
        somma += i * i * i;
    }
    std::cout << somma << std::endl;
    return 0;
}
