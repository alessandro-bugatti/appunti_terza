#include <iostream>
#include <cmath>

/**
 * Calcola l'ipotenusa dati i due cateti
 * @param c1 Primo cateto
 * @param c2 Secondo cateto
 * @return Valore dell'ipotenusa
 */
double ipotenusa(double c1, double c2) {
    double risultato = sqrt(c1*c1 + c2*c2);
    return risultato;
}

int main() {
    double r = ipotenusa(5, 17);
    std::cout << r << std::endl;
    return 0;
}