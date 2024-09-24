#include <iostream>

float calcola_paga (float vendite) {
    float risultato = 200;
    if (vendite < 5000) {
        risultato += vendite * 0.05;
    } else if (vendite < 10000) {
        risultato += 5000 * 0.05 + (vendite - 5000) * 0.07;
    } else {
        risultato += 5000 * 0.05 + 5000 * 0.07 + (vendite - 10000) * 0.09;
    }
    return risultato;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
