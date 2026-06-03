#include <iostream>
#include <fstream>

int main() {
    std::ifstream in("output.txt");
    if (!in) {
        std::cout << "Errore nell'apertura del file." << std::endl;
        return 1;
    }
    int N, conta = 0;
    in >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        in >> temp;
        if (temp < 1000000000) {
            conta++;
        }
    }
    std::cout << "I numeri < 1000000000 sono "
        << conta << std::endl;
    return 0;
}
