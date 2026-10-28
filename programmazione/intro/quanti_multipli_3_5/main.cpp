#include <iostream>

int main() {
    int N, contatore = 0;
    std::cout << "Inserisci un numero positivo: ";
    std::cin >> N;
    for (int i = 15; i < N; ++i) {
        if (i % 3 == 0 && i % 5 == 0) {
            contatore++;
        }
    }
    std::cout << "Ci sono " << contatore << " numeri multipli sia di 3 che di 5" << std::endl;
    //Si poteva anche fare con questa semplice formula ...
    std::cout << "Ci sono " << N / 15 << " numeri multipli sia di 3 che di 5" << std::endl;

    return 0;
}
