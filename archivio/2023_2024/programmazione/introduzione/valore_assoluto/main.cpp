#include <iostream>

int main() {
    float n, assoluto;
    std::cout << "Inserisci un numero a capocchia: ";
    std::cin >> n;
    assoluto = n;
    if (assoluto >= 0){
        assoluto = -assoluto;
    }
    std::cout << "Il valore assoluto di " << n << " è "
        << assoluto << std::endl;

    return 0;
}
