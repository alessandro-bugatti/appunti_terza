#include <fstream>
#include <iostream>

int main() {
    std::ifstream in("input.txt");
    //Controllo sull'apertura del file
    //Va letto come "se non è aperto ...."
    if (!in) {
        std::cout << "Errore nell'apertura del file input.txt" << std::endl;
        return 1;
    }
    std::string riga;
    while(getline(in, riga)) {
        std::cout << riga << std::endl;
    }
    return 0;
}
