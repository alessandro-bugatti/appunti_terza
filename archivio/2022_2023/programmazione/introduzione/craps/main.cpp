#include <iostream>
#include <ctime>

int main() {
    int dado1, dado2, totale, scelta;
    float credito, giocata;
    credito = 1000;
    srand(time(NULL));
    do {
        dado1 = rand() % 6 + 1;
        dado2 = rand() % 6 + 1;
        totale = dado1 + dado2; // totale = rand()%11 + 2; così NO
        std::cout << "Credito disponibile: " << credito << " euro" << std::endl;
        std::cout << "Quanti soldi vuoi puntare? ";
        std::cin >> giocata;
        std::cout << "Primo lancio: " << totale << std::endl;
        if (totale == 7 || totale == 11) {
            std::cout << "Hai vinto" << std::endl;
            credito += giocata;
        } else if (totale == 2 || totale == 3 || totale == 12) {
            std::cout << "Hai perso" << std::endl;
            credito -= giocata;
        } else {
            int target = totale;
            std::cout << "Il target è " << target << std::endl;
            dado1 = rand() % 6 + 1;
            dado2 = rand() % 6 + 1;
            totale = dado1 + dado2;
            std::cout << "Lancio: " << totale << std::endl;
            while (totale != target && totale != 7) {
                dado1 = rand() % 6 + 1;
                dado2 = rand() % 6 + 1;
                totale = dado1 + dado2;
                std::cout << "Lancio: " << totale << std::endl;
            }
            if (totale == 7) {
                std::cout << "Hai perso" << std::endl;
                credito -= giocata;
            } else {
                std::cout << "Hai vinto" << std::endl;
                credito += giocata;
            }
        }
        std::cout << "Vuoi continuare a giocare (1 - sì, 0 - no): ";
        std::cin >> scelta;
    }while(scelta == 1);
    std::cout << "Ti sono rimasti " << credito << " euro" << std::endl;
    return 0;
}
