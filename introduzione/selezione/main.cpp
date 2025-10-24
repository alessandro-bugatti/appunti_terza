#include <iostream>

int main() {
    int a, b;
    std::cout << "inserisci il primo numero: ";
    std::cin >> a;
    std::cout << "inserisci il secondo numero: ";
    std::cin >> b;
    if (a < b){
        std::cout << "il primo numero è più piccolo del secondo" << std::endl;
    }else if (a > b){
        std::cout << "il primo numero è maggiore del secondo" << std::endl;
    }else {
        std::cout << "i due numeri sono uguali" << std::endl;

    }
    return 0;
}