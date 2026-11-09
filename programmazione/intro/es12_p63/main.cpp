#include <iostream>

int main() {
    int N, conta = 0;
    char C;
    std::cout << "Inserisci un numero positivo: ";
    std::cin >> N;
    std::cout << "Inserisci un carettere: ";
    std::cin >> C;
    for (int i = 0; i < N; ++i) {
        conta++;
        std::cout << C;
        if (conta == 5) {
            std::cout << std::endl;
            conta = 0;
        }
    }
    std::cout << std::endl;
    return 0;
}
