#include <iostream>

int main() {
    int a, b;
    std::cout << "Inserisci il primo numero: ";
    std::cin >> a;
    std::cout << "Inserisci il secondo numero: ";
    std::cin >> b;
    if (b < a) {
        int temp = a;
        a = b;
        b = temp;
    }
    std::cout << a << " " << b << std::endl;


    return 0;
}
