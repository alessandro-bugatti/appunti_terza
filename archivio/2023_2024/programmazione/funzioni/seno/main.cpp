#include <iostream>
#include <cmath>

double seno(double angolo, int n){
    double risultato = 0;
    for (int i = 0; i < n; ++i) {
        double elemento = 0;

        risultato += elemento;
    }
    return risultato;
}

int main() {
    double angolo = M_PI / 6;
    int n = 7;
    std::cout << "Nostra versione: sin(" << angolo / M_PI * 180
              << ") = " << seno(angolo, n) << std::endl;
    std::cout << "Libreria: sin(" << angolo / M_PI * 180
        << ") = " << sin(angolo) << std::endl;
    return 0;
}
