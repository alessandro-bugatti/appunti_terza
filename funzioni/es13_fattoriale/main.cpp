#include <iostream>

int fattoriale(int n) {
    //Non necessario
    if (n == 0) {
        return 1;
    }
    int f = 1;
    for (int i = 1; i <= n; ++i) {
        f *= i;
    }
    return f;
}

int main() {
    int n;
    std::cout << "Inserisci un numero: ";
    std::cin >> n;
    std::cout << "Il fattoriale di " << n << " è " <<
        fattoriale(n) << std::endl;

    return 0;
}