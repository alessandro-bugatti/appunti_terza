#include <iostream>

int main() {
    std::string originale = "Scrivere un programma che faccia inserire all’utente una stringa di testo, su un’unica riga, di "
    "lunghezza qualsiasi e che, successivamente, la ristampi a video dandole una formattazione "
    "a \"bandiera\" con una lunghezza massima di ogni singola riga di L caratteri.";
    std::cout << originale << std::endl;
    const int L = 40;

    while(originale.size() > L) {
        int indice = L - 1;
        while(originale.at(indice) != ' ') {
                indice--;
        }
        std::cout << originale.substr(0, indice) << std::endl;
        originale.erase(0, indice + 1);
    }
    std::cout << originale << std::endl;
    return 0;
}
