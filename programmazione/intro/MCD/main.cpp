#include <iostream>

int main() {
    int a, b, MCD;
    std::cout << "Inserisci due numeri interi positivi";
    std::cin >> a >> b;
    if (a < b) {
        MCD = a;
    }else {
        MCD = b;
    }
    while ( !(a % MCD == 0 && b % MCD == 0)) {
        MCD--;
    }
    std::cout << "IL MCD tra " << a << " e " << b
        << " è "  << MCD  << std::endl;
    return 0;
}
