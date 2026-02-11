#include <iostream>

int main() {
    const int DIM = 20;
    int v[DIM], scelta;
    for (int i = 0; i < DIM; ++i) {
        v[i] = rand() % 101;
    }

    int indice, n_elementi = DIM;
    for (int i = 0; i < n_elementi; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "Vuoi inserire (1) o rimuovere (2):";
    std::cin >> scelta;
    std::cout << "Inserisci l'indice dell'elemento: ";
    std::cin >> indice;
    while (indice > 0 && indice <= n_elementi) {
        indice--; //Riallineamento dell'indice con gli indice del vettore che partono da zero
        if (scelta == 1) {
            if (n_elementi >= DIM) {
                std::cout << "Non c'è più spazio per inserire valori!" << std::endl;
            }
            else {
                for (int i = n_elementi - 1; i >= indice; --i) {
                    v[i+1] = v[i];
                }
                std::cout << "Che valore vuoi inserire: ";
                int valore;
                std::cin >> valore;
                v[indice] = valore;
                n_elementi++;
            }
        }else {
            for (int i = indice; i < n_elementi - 1; ++i) {
                v[i] = v[i+1];
            }
            n_elementi--;
        }
        for (int i = 0; i < n_elementi; ++i) {
            std::cout << v[i] << " ";
        }
        std::cout << "Vuoi inserire (1) o rimuovere (2):";
        std::cin >> scelta;
        std::cout << "\n\nInserisci l'indice dell'elemento: ";
        std::cin >> indice;
    }
    return 0;
}