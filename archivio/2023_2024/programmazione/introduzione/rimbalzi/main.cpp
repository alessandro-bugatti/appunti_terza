#include <iostream>


int main() {
    float H;
    int rimbalzi = 0;
    std::cout << "Inserisci l'altezza in cm: ";
    std::cin >> H;
    while(H > 0.1) {
        H = H * 0.5;
        rimbalzi++; //rimbalzi = rimbalzi + 1;
    }
    std::cout << "Il numero di rimbalzi è " << rimbalzi << std::endl;
    return 0;
}
