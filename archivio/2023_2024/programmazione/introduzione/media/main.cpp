#include <iostream>

int main() {
    int n_voti;
    float voto, media, somma_voti;
    std::cout << "Inserire il numero di voti: ";
    std::cin >> n_voti;
    for (int i = 0; i < n_voti; ++i) {
       std::cout << "Inserire un voto: ";
       std::cin >> voto;
       while (!(voto >=1 && voto <= 10)) {
           std::cout << "Inserire un voto: ";
           std::cin >> voto;
       }
       somma_voti += voto;
    }
    media = somma_voti / n_voti;
    std::cout << "La media è : " << media << std::endl;
    if (media < 6) {
        std::cout << "La media è insufficiente" << std::endl;
    } else {
        std::cout << "La media è sufficiente" << std::endl;
    }
    return 0;
}
