#include <iostream>
#include <fstream>

int main() {
    const int N = 100000;
    std::ofstream out("output.txt");
    //Controllo del successo dell'apertura
    if (!out) {
        std::cout << "Errore nell'apertura del file." << std::endl;
        return 1;
    }
    out << N << std::endl;
    for (int i = 0; i < N; ++i) {
        out << rand() << std::endl;
    }
    out.close();

    return 0;
}
