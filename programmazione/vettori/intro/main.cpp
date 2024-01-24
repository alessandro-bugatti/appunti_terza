#include <iostream>

int main() {
    const int MAX_IMPIEGATI = 30;
    int n_impiegati;
    float stipendi[MAX_IMPIEGATI];
    std::cout << "INserisci il numero di impiegati (<" << MAX_IMPIEGATI << "): ";
    std::cin >> n_impiegati;
    for (int i = 0; i < n_impiegati; ++i) {
        std::cout << "Inserisci lo stipendio: ";
        std::cin >> stipendi[i];
    }

    //Faccio qualcosa

    for (int i = 0; i < n_impiegati; ++i) {
        std::cout << stipendi[i] << std::endl;
    }

    return 0;
}
