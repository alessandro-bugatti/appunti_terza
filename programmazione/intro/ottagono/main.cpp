#include <iostream>

int main() {
    int N = 2;

    //RIga orizzontale superiore quella inferiore è uguale
    for (int i = 0; i < N; ++i) {
        std::cout << " ";
    }
    for (int i = 0; i < N; ++i) {
        std::cout << "_";
    }
    std::cout << std::endl;
    //Parte superiore inclinata
    int spazi_prima, spazi_dentro;
    spazi_prima = N - 1;
    spazi_dentro = N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < spazi_prima; ++j) {
            std::cout << " ";
        }
        std::cout << "/";
        for (int i = 0; i < spazi_dentro; ++i) {
            std::cout << " ";
        }
        std::cout << "\\" << std::endl;
        spazi_prima--;
        spazi_dentro += 2;
    }
    //Parte centrale dell'ottagono
    for (int i = 0; i < N; ++i) {
        std::cout << "|";
        for (int i = 0; i < 3*N - 2; ++i) {
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
    }
    spazi_prima = 0;
    spazi_dentro = 3*N - 2;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < spazi_prima; ++j) {
            std::cout << " ";
        }
        std::cout << "\\";
        for (int i = 0; i < spazi_dentro; ++i) {
            std::cout << " ";
        }
        std::cout << "/ " << std::endl;
        spazi_prima++;
        spazi_dentro -= 2;
    }

    //RIga orizzontale inferiore
    for (int i = 0; i < N; ++i) {
        std::cout << " ";
    }
    for (int i = 0; i < N; ++i) {
        std::cout << "_";
    }
    std::cout << std::endl;

    return 0;
}
