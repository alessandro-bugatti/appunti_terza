#include <iostream>
#include <cmath>
#include <ctime>

int main() {
    int numero;
    //Serve a randomizzare la sequenza dei numeri generati, va chiamata
    //una sola volta all'inizio del programma
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        //rand genera un numero casuale compreso tra 0 e un massimo definito dal
        //compilatore, nel nostro caso 2^15
        numero = rand() % 6 + 1;
        /* idea balorda
        while (numero > 6){
            numero = rand();
        }*/
        std::cout <<  numero << std::endl;
    }
    return 0;
}
