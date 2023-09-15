#include <iostream>

int main() {
    int N;
    std::cout << "Inserisci un numero" << std::endl;
    std::cin >> N;
    int somma_pari = 0, somma_dispari = 0;
    bool pari = false;
    while (N > 0){
        int cifra = N % 10;
        if (pari){
            somma_pari += cifra;
            pari = false;
        }
        else{
            somma_dispari += cifra;
            pari = true;
        }

        N /= 10;
    }
    if (somma_dispari - somma_pari == 0)
        std::cout << "Il numero è divisibile per 11" << std::endl;
    else
        std::cout << "Il numero non è divisibile per 11" << std::endl;
    return 0;
}
