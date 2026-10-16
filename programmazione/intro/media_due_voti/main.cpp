#include <iostream>

int main() {
    float voto1, voto2, media;
    std::cout << "Inserisci il primo voto: ";
    std::cin >> voto1;
    std::cout << "Inserisci il secondo voto: ";
    std::cin >> voto2;
    media = (voto1 + voto2) / 2;
    std::cout << "La media è " << media << std::endl;
    return 0;
}
