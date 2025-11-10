#include <iostream>

int main() {
    int giorno, giorni_mese, mese, conta=0;
    std::cout << "inserisci il mese: ";
    std::cin >> mese;
    std::cout << "inserisci il giorno della settimana: ";
    std::cin >> giorno;
    std::cout << "   L   M   M   G   V   S   D" << std::endl;

    if (mese==2) {
        giorni_mese=28;
    }
    else if (mese==11 || mese==4 || mese== 6 || mese==9) {
        giorni_mese=30;
    }
    else {
        giorni_mese=31;
    }

    for (int i=0; i<giorno-1; i++) {
        std::cout << "    ";
    }
    conta=giorno-1;
    for (int i=1; i<=giorni_mese; i++) {
        if (i<10) {
            std::cout << "   ";
        }
        else {
            std::cout << "  ";
        }
        std::cout << i;
        conta++;
        if (conta==7) {
            std::cout << std::endl;
            conta=0;
        }
    }



    return 0;
}