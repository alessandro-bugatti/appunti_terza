/* Gioco del Chuck-a-luck
 * Chuck-a-Luck è un gioco di dadi in cui
 * il giocatore scommette sul risultato del lancio di tre dadi.
 * Se il numero scelto appare una volta: il giocatore riceve una vincita pari alla sua puntata
 * Se il numero scelto appare due volte: il giocatore riceve il doppio della sua puntata
 * Se il numero scelto appare tre volte: il giocatore riceve il triplo della sua puntata.
 * Se il numero scelto non appare il giocatore perde tutta la puntata.
 Video: https://www.youtube.com/watch?v=amgQAqjPKPc
 Esecuzione: https://asciinema.org/a/692864
*/
#include <iostream>


int lancio_dado() {
    return rand()%6+1;
}

int calcola_risultato(int l1, int l2, int l3, int n, int puntata) {
        int conta=0;
        if (n==l1) {
            conta++;
        }
        if (n==l2) {
            conta++;
        }
        if (n==l3) {
            conta++;
        }
        if (conta==0) {
            return -puntata;
        }
        return conta*puntata;
}

void stampa_faccia(int n) {
    if (n == 1) {
        std::cout << "+-------+\n";
        std::cout << "|       |\n";
        std::cout << "|   o   |\n";
        std::cout << "|       |\n";
        std::cout << "+-------+\n";
    }
    else if (n == 2) {
        std::cout << "+-------+\n";
        std::cout << "| o     |\n";
        std::cout << "|       |\n";
        std::cout << "|     o |\n";
        std::cout << "+-------+\n";
    }
    else if (n == 3) {
        std::cout << "+-------+\n";
        std::cout << "| o     |\n";
        std::cout << "|   o   |\n";
        std::cout << "|     o |\n";
        std::cout << "+-------+\n";
    }
    else if (n == 4) {
        std::cout << "+-------+\n";
        std::cout << "| o   o |\n";
        std::cout << "|       |\n";
        std::cout << "| o   o |\n";
        std::cout << "+-------+\n";
    }
    else if (n == 5) {
        std::cout << "+-------+\n";
        std::cout << "| o   o |\n";
        std::cout << "|   o   |\n";
        std::cout << "| o   o |\n";
        std::cout << "+-------+\n";
    }
    else if (n == 6) {
        std::cout << "+-------+\n";
        std::cout << "| o   o |\n";
        std::cout << "| o   o |\n";
        std::cout << "| o   o |\n";
        std::cout << "+-------+\n";
    }
}

int main() {
    int puntata, credito=100, num_scelto, l1 ,l2, l3;
    bool continua=true;
    std::cout << "Gioco del chuck a luck" << std::endl;
    do {
        std::cout << "Scegli un numero da 1 a 6: ";
        std::cin >> num_scelto;
        std::cout << "Scegli quanti ciollari puntare (massimo " << credito << "): ";
        std::cin >> puntata;
        l1= lancio_dado();
        l2= lancio_dado();
        l3= lancio_dado();
        stampa_faccia(l1);
        stampa_faccia(l2);
        stampa_faccia(l3);
        credito+= calcola_risultato(l1,l2,l3,num_scelto,puntata);
        std::cout<< "Il tuo nuovo credito e': " << credito << std::endl;
        if (credito > 0){
            int scelta;
            std::cout<<"Vuoi fare un'altra puntata (1 per continuare, 0 per terminare)?: ";
            std::cin >> scelta;
            if (scelta == 0)
                continua = false;
        }
    }while (credito > 0 and continua);
    return 0;
}