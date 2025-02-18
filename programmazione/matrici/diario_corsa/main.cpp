#include <iostream>

int main() {
    const int MESI = 12;
    const int GIORNI  = 31;
    float diario[MESI][GIORNI];

    //Inizializzo la matrice con tutti zeri
    for (int i = 0; i < MESI; ++i) {
        for (int j = 0; j < GIORNI; ++j) {
            diario[i][j] = 0;
        }
    }

    //Inserimento di una registrazione di una corsa
    int mese, giorno;
    float corsa;
    //Modificare questa parte in modo da poter inserire valori tanti quanti decide l'utente
    std::cout << "Inserisci il mese (1-12): ";
    std::cin >> mese;
    std::cout << "Inserisci il giorno (1-31): ";
    std::cin >> giorno;
    std::cout << "Quanto hai corso in questa data? (km) ";
    std::cin >> corsa;
    //Inserisco l'input nella casella scelta
    diario[mese - 1][giorno - 1] = corsa;

    //Stampa del contenuto della matrice, tutto
    for (int i = 0; i < MESI; ++i) {
        for (int j = 0; j < GIORNI; ++j) {
            std::cout << diario[i][j] << " ";
        }
        std::cout << std::endl;
    }

    //Stampa solo dei giorni in cui si è corso, con anche la data
    for (int i = 0; i < MESI; ++i) {
        for (int j = 0; j < GIORNI; ++j) {
            if (diario[i][j] > 0) {
                std::cout << "Hai corso " <<  diario[i][j] << " km in data " <<
                    j + 1 << "/" << i + 1 << std::endl;
            }
        }
    }

    //Stampare quanto ha corso nell'anno

    //Stampa per ogni mese quanto ha corso

    //Stampa il mese in cui ha corso di più
    
    return 0;
}