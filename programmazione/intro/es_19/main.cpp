#include <iostream>

int main() {
    int numero_da_indovinare, numero, contatore = 1;
    numero_da_indovinare = rand() % 1000 + 1;
    std::cout << "Prova a indovinare il numero: ";
    std::cin >> numero;
    while (numero != numero_da_indovinare) {
        if (numero > numero_da_indovinare) {
            std::cout << "Il numero inserito è più grande del numero da indovinare" << std::endl;
        }
        else {
            std::cout << "Il numero inserito è più piccolo del numero da indovinare" << std::endl;
        }
        contatore++;
        std::cout << "Prova a indovinare il numero: ";
        std::cin >> numero;
    }
    std::cout << "Hai indovinato dopo " << contatore << "tentativi" << std::endl;

    return 0;
}
