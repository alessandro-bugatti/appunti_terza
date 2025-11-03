#include <iostream>

int main() {
    int casuale, n, tentativi = 1;
    srand(time(NULL));
    casuale = rand()%1000 + 1;
    std::cout << "Inserisci il numero da indovinare: ";
    std::cin >> n;
    while (n != casuale) {
        if (n < casuale) {
            std::cout << "Il tuo numero è più piccolo di quello da indovinare." << std::endl;
        } else {
            std::cout << "Il tuo numero è più grande di quello da indovinare." << std::endl;
        }
        tentativi++;
        std::cout << "Inserisci il numero da indovinare: ";
        std::cin >> n;
    }
    std::cout << "Hai indovinato in "  << tentativi << " tentativi.";
    return 0;
}