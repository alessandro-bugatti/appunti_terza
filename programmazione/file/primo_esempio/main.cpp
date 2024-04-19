#include <fstream>
#include <iostream>

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    //Controllo sull'apertura del file
    //Va letto come "se non è aperto ...."
    if (!in) {
        std::cout << "Errore nell'apertura del file input.txt" << std::endl;
        return 1;
    }
    if (!out) {
        std::cout << "Errore nell'apertura del file output.txt" << std::endl;
        return 1;
    }

    int n;
    in >> n;
    std::cout << "Il numero letto è " << n << std::endl;

    return 0;
}
