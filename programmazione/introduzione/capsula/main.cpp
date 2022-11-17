#include <iostream>

int main(){
    int N, spazi_prima, spazi_dopo, spazi_interni;
    std::cout << "Inserisci il valore di N: ";
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cout << " ";
    }
    for (int i = 0; i < N; ++i) {
        std::cout << "_";
    }
    std::cout << std::endl;
    spazi_prima = N - 1;
    spazi_dopo = N;
    //Stampa la parte superiore della capsula
    for (int i = 0; i < N; ++i) {
        //Codice che scrive una riga della parte superiore della capsula
        for (int j = 0; j < spazi_prima; ++j) {
            std::cout << " ";
        }
        std::cout << "/";
        for (int j = 0; j < spazi_dopo; ++j) {
            std::cout << " ";
        }
        // Il segno \\ stampa una sola \
        // Il segno \n fa andare a capo
        std::cout << "\\\n";
        //Aggiorna il numero di spazi da stampare preparandolo
        //per la riga successiva
        spazi_prima--;
        spazi_dopo += 2;
    }
    spazi_interni = spazi_dopo - 1;
    //Stampa della parte centrale
    for (int i = 0; i < N; ++i) {
        std::cout << "I";
        for (int j = 0; j < spazi_interni; ++j) {
            std::cout << " ";
        }
        std::cout << "I" << std::endl;
    }
    spazi_prima = 0;
    spazi_dopo -= 2;
    //Stampa la parte inferiore della capsula
    for (int i = 0; i < N; ++i) {
        //Codice che scrive una riga della parte superiore della capsula
        for (int j = 0; j < spazi_prima; ++j) {
            std::cout << " ";
        }
        std::cout << "\\";
        for (int j = 0; j < spazi_dopo; ++j) {
            std::cout << " ";
        }
        // Il segno \\ stampa una sola \
        // Il segno \n fa andare a capo
        std::cout << "/\n";
        //Aggiorna il numero di spazi da stampare preparandolo
        //per la riga successiva
        spazi_prima++;
        spazi_dopo -= 2;
    }
    return 0;
}