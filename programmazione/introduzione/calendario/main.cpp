#include <iostream>
#include <iomanip>

int main() {
    int giorni_mese, mese, giorno;
    std::cout<< "inserisci il mese: ";
    std::cin>> mese;
    std::cout<< "inserisci il giorno: ";
    std::cin>> giorno;
    std::cout << std::endl;
    std::cout << "   L   M   M   G   V   S   D" << std::endl;
    if (mese == 4 || mese == 6 || mese == 9 || mese == 11) {
        giorni_mese = 30;
    }else if (mese == 2){
        giorni_mese = 28;
    }else{
        giorni_mese = 31;
    }
    for (int i = 0; i < giorno - 1; ++i) {
        std::cout << "    ";
    }
    for (int i = giorno; i < giorni_mese + giorno; i++){
        std::cout << std::setw(4) << i - giorno + 1;
        if (i % 7 == 0){
            std::cout << std::endl;
        }
    }
    return 0;
}
