#include <iostream>

int main() {
    const int DIM = 20;
    int v[DIM];
    for (int i = 0; i < DIM; ++i) {
        v[i] = rand() % 101;
    }

    int indice, n_elementi = DIM;
    for (int i = 0; i < n_elementi; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "Inserisci l'indice dell'elemento da rimuovere: ";
    std::cin >> indice;
    while (indice > 0 && indice <= n_elementi) {
        indice--; //Riallineamento dell'indice con gli indice del vettore che partono da zero
        for (int i = indice; i < n_elementi - 1; ++i) {
            v[i] = v[i+1];
        }
        n_elementi--;
        for (int i = 0; i < n_elementi; ++i) {
            std::cout << v[i] << " ";
        }
        std::cout << "\n\nInserisci l'indice dell'elemento da rimuovere: ";
        std::cin >> indice;
    }
    return 0;
}