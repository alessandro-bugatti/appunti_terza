#include <iostream>

int main() {
    int n;
    //Questa istruzione inizializza il seme del generatore di numeri
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        n = rand() % 100 + 1;
        std::cout << n << " - ";
    }
    return 0;
}
