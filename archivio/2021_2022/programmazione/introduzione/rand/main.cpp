#include <iostream>
#include <ctime>

using namespace std;

/*
 * Questo programma mostra l'utilizzo della funzione di libreria
 * rand per la generazione di numeri pseudocasuali
 */

int main() {
    //Inizializzo il seme del generatore di numeri casuali
    srand(time(NULL));
    //rand produce numeri interi tra 0 e 32000 e rotti
    int n;
    for (int i = 0; i < 100; i++) {
        n = rand()%6 + 1;
        cout << n << endl;
    }

    //Simulo il lancio di 1000000 di monete
    int testa = 0, croce = 0;
    for (int i = 0; i < 1000000; ++i) {
        int lancio = rand()%2;
        if (lancio == 0)
            testa++;
        else
            croce++;
    }
    cout << "Testa è uscita " << testa << " volte" << endl;
    cout << "Croce è uscita " << croce << " volte" << endl;
    return 0;
}
