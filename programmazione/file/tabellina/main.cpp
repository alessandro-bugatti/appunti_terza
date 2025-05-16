#include <iostream>
#include <fstream>

int main() {
    int numero = 7;
    std::string nomefile;
    std::cout << "Inserisci il numero di cui vuoi la tabellina: " ;
    std::cin >> numero;
    nomefile = "tabellina" + std::to_string(numero) + ".txt";
    std::ofstream out(nomefile);
    if (!out) {
        std::cout << "Errore" << std::endl;
        return 1;
    }
    for (int i = 0; i < 10; ++i) {
        out << numero << " x " << (i + 1) << " = " << numero * (i + 1) << std::endl;
    }
    out.close();
    return 0;
}