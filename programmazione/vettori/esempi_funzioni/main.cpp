#include <iostream>

void riempi_casuale(int v[], int n, int massimo) {
    for (int i = 0; i < n; ++i) {
        v[i] = rand() % massimo;
    }
}

void stampa(int v[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void inverti(int v[], int n) {
    for (int i = 0; i < n; ++i) {
        int temp;
        temp = v[i];
        v[i] = v[n - 1 - i];
        v[n - 1 - i] = temp;
    }
}

int main() {
    const int DIM = 100;
    int v[DIM];
    int n;
    std::cout << "Inserisci il numero di elementi (<=100): ";
    std::cin >> n;
    riempi_casuale(v, n, 50);
    stampa(v, n);
    inverti(v, n);
    stampa(v, n);
    return 0;
}