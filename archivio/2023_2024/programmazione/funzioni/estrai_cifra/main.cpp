#include <iostream>
#include <valarray>

int conta_cifre(int n){
    int conta = 0;
    while (n > 0){
        conta++;
        n /= 10;
    }
    return conta;
}

int estrai_cifra(int n, int k){
    if (k < 1 || k > conta_cifre(n))
        return -1;
    int p = conta_cifre(n) - k;
    int divisore = pow(10, p);
    return (n / divisore) % 10;
}

int main() {
    std::cout << estrai_cifra(12345, 2) << std::endl;
    std::cout << estrai_cifra(12345, 5) << std::endl;
    std::cout << estrai_cifra(12345, 7) << std::endl;
    return 0;
}
