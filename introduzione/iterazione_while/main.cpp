#include <iostream>

int main()
{
    int numeri = 0;
    int n;
    std::cout<< "inserisci un numero: ";
    std::cin >> n;
    while (n>=0)
    {
        numeri++; //numeri = numeri + 1;
        std::cout<< "inserisci un numero: ";
        std::cin >> n;
    }
    std::cout << "hai inserito " <<numeri<< " numeri" <<std::endl;

    return 0;
}