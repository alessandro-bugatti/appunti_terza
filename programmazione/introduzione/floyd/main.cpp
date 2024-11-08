#include <iostream>

int main() {
    int N, numero = 1;
    std::cout << "inserisci N";
    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << numero << " ";
            numero++;
        }
        std::cout << std::endl;
    }
    return 0;
}
