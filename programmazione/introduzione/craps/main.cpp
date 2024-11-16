#include <iostream>

int main() {
    int target, lancio;
    srand(time(NULL));
    std::cout << "**************************************" << std::endl;
    std::cout << "*       GIOCO DEL CRAPS              *" << std::endl;
    std::cout << "**************************************" << std::endl;
    /*Primo lancio
    * se al primo tiro il giocatore fa 7 o 11 ha vinto
    * se al primo tiro il giocatore fa 2, 3 o 12 ha perso
    */
    lancio = rand()%6 + 1 + rand()%6 + 1;
    std::cout << "Il tuo lancio ha prodotto " << lancio << std::endl;
    if (lancio == 7 || lancio == 11) {
        std::cout << "Hai vinto" << std::endl;
    }
    else if(lancio == 2 || lancio == 3 || lancio == 12) {
        std::cout << "Hai perso" << std::endl;
    }
    else {
        /*Dal secondo lancio in poi
        * qualsiasi altro punteggio viene definito "target" e si continua a tirare finchè
            - il giocatore realizza nuovamente il target, in quel caso vince
            - il giocatore realizza un 7, in quel caso perde
        */
        target = lancio;
        lancio = rand()%6 + 1 + rand()%6 + 1;
        std::cout << "Il tuo lancio ha prodotto " << lancio << std::endl;
        while(lancio != target && lancio != 7) {
            lancio = rand()%6 + 1 + rand()%6 + 1;
            std::cout << "Il tuo lancio ha prodotto " << lancio << std::endl;
        }
        if (lancio == target) {
            std::cout << "Hai vinto" << std::endl;
        }
        else {
            std::cout << "Hai perso" << std::endl;
        }
    }

    return 0;
}
