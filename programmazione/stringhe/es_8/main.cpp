#include <iostream>

int main() {
    std::string originale = "Bello questo corso di Informatica",
        modificata;

    for (int i = 0; i < originale.size(); ++i) {
        //std::cout << modificata.find(originale.at(i)) << std::endl;
        if (modificata.find(originale.at(i)) == std::string::npos)
            modificata += originale.at(i);
    }
    std::cout << modificata << std::endl;

    modificata = "";
    bool caratteri[128];
    for (int i = 0; i < 128; ++i) {
        caratteri[i] = false;
    }

    for (int i = 0; i < originale.size(); ++i) {
        //std::cout << modificata.find(originale.at(i)) << std::endl;
        if (caratteri[originale.at(i)] == false) {
            modificata += originale.at(i);
            caratteri[originale.at(i)] = true;
        }

    }
    std::cout << modificata << std::endl;
    return 0;
}
