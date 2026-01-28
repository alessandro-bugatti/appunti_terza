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
    return 0;
}