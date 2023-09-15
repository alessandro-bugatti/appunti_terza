#include <iostream>

int main() {
    float vendita, paga;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Inserisci il valore della merca venduta dal venditore "
            << i + 1 << ": ";
        std::cin >> vendita;
        paga = 200;
        if (vendita <= 5000){
            paga += vendita * 5 / 100;
        }
        else if (vendita <= 10000){
            paga += 5000.0 * 5 / 100 + (vendita - 5000) * 7 / 100;
        }
        else{
            paga += 5000.0 * 5 / 100 + 5000.0 * 7 / 100 + (vendita - 10000) * 9 / 100;
        }
        std::cout << "Il venditore " << i + 1 << " prenderà " << paga << " euro." << std::endl;
    }
    return 0;
}
