#include <iostream>


bool primo(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int quanti_primi(int a, int b) {
    int conta = 0;
    for (int i = a; i < b; ++i) {
        if (primo(i)) {
            conta++;
        }
    }
    return conta;
}

int main() {
    std::cout << quanti_primi(2, 100000) << std::endl;
    return 0;
}
