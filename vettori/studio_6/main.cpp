#include <iostream>

float numero_causale() {
    return (rand() % 1000) / 10.0;
}

int main() {
    const int DIM = 20;
    int a, b;
    float somma = 0;
    float v[DIM];
    for (int i = 0; i < DIM; ++i) {
        v[i] = numero_causale();
    }
    std::cout << "Inserisci a e b: ";
    std::cin >> a >> b;
    while (a >= 0 && b >= 0) {
        for (int i = a; i <= b; ++i) {
            somma += v[i];
        }
        /*Alternativa Torri
        while (a <= b) {
            somma += v[a];
            a++;
        }*/
        std::cout << "La somma tra le posizione " << a <<
            " e " << b << " è " << somma << std::endl;
        std::cout << "Inserisci a e b: ";
        std::cin >> a >> b;
        somma = 0;
    }
    return 0;
}