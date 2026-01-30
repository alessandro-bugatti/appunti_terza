#include <iostream>

int main() {
    const int DIM1 = 10, DIM2 = 5;
    int v1[DIM1], v2[DIM2];
    for (int i = 0; i < DIM1; ++i) {
        // std::cout << "Inserisci un valore: ";
        // std::cin >> v1[i];
        v1[i] = rand() % 10;
    }
    for (int i = 0; i < DIM1; ++i) {
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < DIM2; ++i) {
        // std::cout << "Inserisci un valore: ";
        // std::cin >> v2[i];
        v2[i] = rand() % 10;
    }
    for (int i = 0; i < DIM2; ++i) {
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;
    int contatore = 0;
    for (int i = 0; i < DIM2; ++i) {
        for (int j = 0; j < DIM1; ++j) {
            if (v2[i] == v1[j]) {
                contatore++;
                break;
            }
        }
    }

    if (contatore == DIM2) {
        std::cout << "Il secondo vettore è compreso nel primo." << std::endl;
    } else {
        std::cout << "Il secondo vettore non è compreso nel primo" << std::endl;
    }
    return 0;
}