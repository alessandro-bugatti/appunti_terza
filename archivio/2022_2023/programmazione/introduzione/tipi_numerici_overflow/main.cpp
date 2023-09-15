#include <iostream>

int main() {
    double a, b;
    std::cout << "Inserisci due numeri interi compresi tra uno e due miliardi" << std::endl;
    std::cin >> a >> b;
    std::cout << "La somma è : " << a + b << std::endl;
    std::cout << "La differenza è : " << a - b << std::endl;
    std::cout << "Il prodotto è : " << a * b << std::endl;


    return 0;
}
