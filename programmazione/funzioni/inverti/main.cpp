#include <iostream>

int inverti(int n) {
    int n_invertito = 0;
    while (n > 0) {
        int cifra = n % 10;
        n_invertito = n_invertito * 10 + cifra;
        n = n / 10;
    }
    return n_invertito;
}

int main() {
    std::cout << inverti(234) << std::endl;
    return 0;
}