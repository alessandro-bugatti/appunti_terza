#include <iostream>

int main() {
    int N, M, S, K;
    //Nessun output se non il risultato
    //std::cout << "Inserisci due numeri: ";
    std::cin >> N >> M;
    //Prima versione senza controllo sulla parità
    //Non prende tutti i punti
    S = N + M;
    if (S % 2 == 0){
        K = N * M;
    }
    else{
        K = M - N;
    }

    std::cout << S ;
    std::cout << " " << K << std::endl;
    return 0;
}
