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
    float f;
    std::string s;
    in >> n >> f >> s;
    std::cout << "Il numero letto è " << n << std::endl;
    std::cout << "Il float letto è " << f << std::endl;
    std::cout << "La stringa letta è " << s << std::endl;

    out << "Ciao" << std::endl;
    for (int i = 0; i < 10; ++i) {
        out << (i+1) << std::endl;
    }
    in.close();
    out.close();
    return 0;
}
