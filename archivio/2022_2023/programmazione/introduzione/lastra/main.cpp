#include <iostream>

int main() {
    float base, altezza; //Dimensioni della lastra in metri
    float lato_ritaglio, lato_ritaglio_max; //Dimensioni del lato del quadrato da tagliare
    float volume, volume_max; //Volume del contenitore dopo il taglio
    const float AUMENTO = 0.01;
    std::cout << "Inserisci la base della lastra rettangolare: ";
    std::cin >> base;
    std::cout << "Inserisci l'altezza della lastra rettangolare: ";
    std::cin >> altezza;
    lato_ritaglio = 0;
    volume_max = 0;
    while (base - lato_ritaglio*2 > 0 && altezza -lato_ritaglio*2 >0){
        volume = (base - lato_ritaglio*2) * (altezza - lato_ritaglio*2) * lato_ritaglio;
        if (volume > volume_max){
            volume_max = volume;
            lato_ritaglio_max = lato_ritaglio;
        }
        std::cout << "Con un lato di " << lato_ritaglio << " metri si ottiene un volume di "
            << volume << " metri cubi" << std::endl;
        lato_ritaglio += AUMENTO;
    }
    std::cout << "Il volume maggiore verrà ottenuto con un ritaglio di "
        << lato_ritaglio_max << " metri.";

    return 0;
}
