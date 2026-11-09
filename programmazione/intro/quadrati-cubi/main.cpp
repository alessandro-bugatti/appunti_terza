#include <iostream>

int main() {
    int N, somma_quadrati = 0, somma_cubi = 0;
    std::cout << "Inserisci un numero positivo: ";
    std::cin >> N;
    for (int i = 1; i <= N; ++i) {
        if (i % 2 == 0) {
            std::cout << i * i << std::endl;
            somma_quadrati += i * i;
        }
        else {
            std::cout << i * i * i << std::endl;
            somma_cubi += i * i * i;
        }

    }

    std::cout << "QUadrati :" << somma_quadrati << std::endl;
    std::cout << "Cubi :" << somma_cubi << std::endl;
    return 0;
}
