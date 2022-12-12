#include <iostream>

int MCD(int m, int n){
    int resto = m % n;
    while (resto != 0){
        m = n;
        n = resto;
        resto = m % n;
    }
    return n;
}

int main() {
    std::cout << MCD(27, 45) << std::endl;
    return 0;
}
