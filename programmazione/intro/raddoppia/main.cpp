#include <iostream>

/*
 * Dato in input un capitale iniziale e un tasso di interesse
 * annuo, valutare dopo quanti
 * anni il capitale è raddoppiato
 */

int main() {
    float capitale_iniziale, tasso, capitale_finale;
    int anni = 0;
    std::cout << "Inserisci il capitale iniziale: ";
    std::cin >> capitale_iniziale;
    std::cout << "Inserisci il tasso annuo: ";
    std::cin >> tasso;
    capitale_finale = capitale_iniziale;
    while (capitale_finale < capitale_iniziale * 2) {
        capitale_finale = capitale_finale +
            capitale_finale * tasso / 100;
        //capitale_finale *= (100 + tasso) / 100;
        anni++;
    }
    std::cout << "Dopo " << anni << " anni il capitale è diventato "
        << capitale_finale << " euro partendo da " << capitale_iniziale
        << " euro" << std::endl;
    return 0;
}
