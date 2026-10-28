#include <iostream>

int main() {
    int N;
    std::cout << "Inserisci un numero positivo: ";
    std::cin >> N;
    for (int i = 1; i <= N; ++i) {
        std::cout << i << " -> " << i * i << std::endl;
    }
    return 0;
}
