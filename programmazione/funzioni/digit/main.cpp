#include <iostream>

int n_digit(int n){
    int conta = 0;
    while (n > 0){
        conta++;
        n = n / 10;
    }
    return conta;
}

/**
 * Ritorna la k-esima cifra del numero n
 * 8472365
 * 7654321
 * @param n il numero da cui estrarre la cifra
 * @param k la posizione della cifra
 * @return la cifra in posizione k, -1 se la posizione non è valida
 */

int digit(int n, int k){
    //se il valore di k non è valido
    if (k <= 0 || k > n_digit(n))
        return -1;
    for (int i = 0; i < k - 1; ++i) {
        n = n / 10;
    }
    return n % 10;
}

/**
 * Ritorna la k-esima cifra del numero n
 * 8472365
 * 1234567
 * 7654321
 * @param n il numero da cui estrarre la cifra
 * @param k la posizione della cifra
 * @return la cifra in posizione k, -1 se la posizione non è valida
 */

int digit_reverse(int n, int k){
    int indice = n_digit(n) + 1 - k;
    return digit(n, indice);
}


int main() {
    int n = 8472365;
    std::cout << n_digit(n) << std::endl;

    for (int i = -2; i < 10 ; ++i) {
        std::cout << i << " " << digit(n, i) << std::endl;
    }
    for (int i = -2; i < 10 ; ++i) {
        std::cout << i << " " << digit_reverse(n, i) << std::endl;
    }
    return 0;
}
