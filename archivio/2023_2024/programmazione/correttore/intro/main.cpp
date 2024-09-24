#include <iostream>

int main() {
    int N, M;
    int S, K;

    //Input

    std::cin >> N >> M;

    //Soluzione del problema
    S = N + M;
    if (S % 2 == 0){
        K = N * M;
    }else{
        K = N - M;
    }

    //Output
    std::cout << S << " " << K << std::endl;
    return 0;
}
