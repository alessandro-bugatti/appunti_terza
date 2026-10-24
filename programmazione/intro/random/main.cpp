#include <iostream>

int main() {
    //srand: inizializza il seme del generatore di numeri pseudo casuali
    //da una bella mescolata all'urna
    //se serve, viene chiamata solo una volta all'inizio del programma
    srand(time(NULL));

    //rand: funzione di base per la produzione di numeri casuali
    //produce un numero intero compreso tra 0 e MAX_INT
    int n = rand() % 6;
    std::cout << n << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << rand() % 6<< std::endl;
    }
    return 0;
}
