#include <iostream>

int lancio_dado() {
    return rand() % 6 +1;
}

void verifica(int &d, int n, int &usciti) {
    d = lancio_dado();
    if (d == n) {
        usciti++;
    }
}

int main() {
    srand(time(NULL));
    int soldi, puntata;
    int d1, d2, d3;
    int numero_scelto, volte = 0, continua;

    soldi = 100;

    do {
        std::cout << "Soldi attuali: " << soldi << std::endl;
        std::cout << "Fai la tua puntata: ";
        std::cin >> puntata;
        while (puntata > soldi) {
            std::cout << "Non hai abbastanza soldi";
            std::cout << "Fai la tua puntata: ";
            std::cin >> puntata;
        }
        //Gioco
        std::cout << "Scegli il tuo numero: (1-6)";
        std::cin >> numero_scelto;
        verifica(d1, numero_scelto, volte);
        verifica(d2, numero_scelto, volte);
        verifica(d3, numero_scelto, volte);
        std::cout << "Lanci: " << d1 << " - " << d2 << " - " << d3 << std::endl;
        std::cout << "Uscito" << volte << " volte.";
    }while (continua == 1);


    return 0;
}