#include <iostream>

void trova_sostituisci(std::string &testo, const std::string &parola,
    const std::string &cambio) {
    int pos = 0;
while ((pos = testo.find(parola, pos)) != std::string::npos) {
    testo.replace(pos, parola.size(), cambio);
}
}

int main() {
    std::string testo, cercata, nuova;
    std::cout << "Inserisci il testo: ";
    getline(std::cin, testo);
    std::cout << "Inserisci la parola da sostituire: ";
    getline(std::cin, cercata);
    std::cout << "Inserisci la nuova parola: ";
    getline(std::cin, nuova);


    return 0;
}