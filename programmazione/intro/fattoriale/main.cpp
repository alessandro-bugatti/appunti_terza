#include <iostream>

int main() {
    int N, fattoriale = 1;
    std::cout << "Inserisci un numero positivo: ";
    std::cin >> N;
    for (int i = 1; i <= N; ++i) {
        fattoriale = fattoriale * i;
    }
    std::cout << "Il fattoriale di " << N << " è "
        << fattoriale << std::endl;
    return 0;
}
