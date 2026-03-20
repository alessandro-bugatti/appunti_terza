#include <iostream>

int main() {
    const int N = 5, M = 6;
    int m[N][M];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            m[i][j] = rand() % 101;
        }
    }
    int scelta, n;
    std::cout << "Vuoi fare la somma per riga (1), per colonna(2) o uscire (-1)?";
    std::cin >> scelta;

    while (scelta != -1) {
        if (scelta == 1) {
            std::cout << "Inserisci la riga che ti interessa: ";
            std::cin >> n;
            n--;
            int somma = 0;
            for (int i = 0; i < M; ++i) {
                somma += m[n][i];
            }
            std::cout << "La somma degli elementi in riga "
                << n + 1 << " è " << somma << std::endl;
        }else {

        }
        std::cout << "Vuoi fare la somma per riga (1), per colonna(2) o uscire (-1)?";
        std::cin >> scelta;
    }


    return 0;
}