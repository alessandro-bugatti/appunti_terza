#include <iostream>
/*
 *programma per l'area di un rettangolo

 */
int main() {
    float base, altezza;//variabili di input
    float area;//variabili di output
    std::cout << "Inserisci la base: ";
    std::cin >> base;
    std::cout << "Inserisci l'altezza: ";
    std::cin >> altezza;
    area = base * altezza;
    std::cout << "L'area di un rettangolo con base "
        << base << " e altezza " << altezza << " è "
        << area;
    return 0;
}