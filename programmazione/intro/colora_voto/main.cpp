#include <iostream>

/*
 * PRogramma che simula la colorazione di un voto
 */

int main() {
    float voto;
    //Prima versione, solo rosso o verde
    std::cout << "Inserisci il voto: ";
    std::cin >> voto;
    std::cout << "Prima versione:" << std::endl;
    if (voto >= 6) {
        std::cout << "verde" << std::endl;
    }
    else {
        std::cout << "rosso" << std::endl;
    }

    //Seconda versione
    std::cout << "Seconda versione:" << std::endl;
    if (voto >= 6) {
        std::cout << "verde" << std::endl;
    }
    else if (voto >= 5) {
        std::cout << "arancione" << std::endl;
    }
    else {
        std::cout << "rosso" << std::endl;
    }
    return 0;
}