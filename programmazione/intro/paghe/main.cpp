#include <iostream>

int main() {
    float vendita, paga;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Venditore " << i + 1 << std::endl;
        std::cout << "Quanto hai venduto: ";
        std::cin >> vendita;
        paga = 200;
        if (vendita < 5000) {
            paga += vendita * 0.05;
        } else if (vendita < 10000) {
            paga += 5000 * 0.05 + (vendita - 5000) * 0.07;
        } else {
            paga += 5000 * 0.05 + // i primi 5000 euro al 5%
                    5000 * 0.07 + // gli altri 5000 da 5000 a 10000 sono al 7%
                    (vendita - 10000) * 0.09; //tutto il resto al 9%
        }
        std::cout << "PAga del venditore " << i + 1 << " . "
            << paga << std::endl;
    }
    return 0;
}
