#include <iostream>

int main() {
    int N, M; //input
    int S, K; //output
    //std::cout << "Inserisci due numeri naturali: ";
    std::cin >> N >> M;
    S = N + M;
    if (S % 2 == 0) { //sommma pari
        K = N * M;
    }else { //somma dispari
        K = N - M;
    }
    std::cout << S << " " << K << std::endl
    return 0;
}