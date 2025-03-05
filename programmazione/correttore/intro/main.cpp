#include <iostream>

int main() {
    int N, M, S, K;
    //std::cout << "Inserisci due numeri interi: ";
    std::cin >> N >> M;
    S = N + M;
    if (S % 2 == 0) {
        K = N * M;
    }
    else {
        K = N - M;
    }
    //std::cout << "La soluzione è ";
    std::cout << S  << " " << K;
    return 0;
}