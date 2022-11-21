#include <iostream>

int main() {
    int n, m;
    int divisore;
    std::cout << "Inserisci due numeri interi: ";
    std::cin >> n >> m;
    //Per motivi di efficienza sarebbe meglio partire dal minore
    divisore = n;
    while(n % divisore != 0 || m % divisore != 0){
        divisore--;
    }
    std::cout << "Il MCD è " << divisore;
    return 0;
}
