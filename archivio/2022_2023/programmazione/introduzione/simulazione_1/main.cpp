#include <iostream>

int main() {
    int n, fattoriale = 1;
    std::cout << "Inserisci il numero di cui vuoi calcolare il fattoriale: ";
    std::cin >> n;
    for (int i = 0; i < n; i++){
        fattoriale *= (i + 1);
    }
    std::cout << "Il fattoriale è " << fattoriale;
    return 0;
}
