#include <iostream>

int main() {
    int N;
    char C;
    std::cout << "Inserisci un numero positivo: ";
    std::cin >> N;
    std::cout << "Inserisci un carettere: ";
    std::cin >> C;
    for (int i = 0; i < N; ++i) {
        std::cout << C;
    }
    std::cout << std::endl;
    return 0;
}
