#include <iostream>

int main() {
    int N, M;
    std::cout << "Inserisci N: ";
    std::cin >> N;
    std::cout << "Inserisci M: ";
    std::cin >> M;
    //Devo stampare N righe
    for (int i = 0; i < N; ++i) {
        //Stampa una singola riga
        for (int j = 0; j < M; ++j) {
            std::cout << "x";
        }
        std::cout << std::endl;
    }
    return 0;
}
